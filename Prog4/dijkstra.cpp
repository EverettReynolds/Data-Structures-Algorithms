#include "graph.h"
#include "queue.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>
#include <cstdlib>
#include <iomanip>

using namespace std; // I'm sorry I keep turning in things with seg faults, I'm going to try and brush up on my code over christmas break to figure out why I keep running into so many.

struct VertexType
{
  string name;
  bool marked;
  int distance;
  string previous;
  bool operator<(const VertexType &vertex) const // Weird Error when using vector sort() method. Had to overload the operator to get the proper output, alternatively, another sort method could be written.
                                                  // this error was most likely because I created the struct above for my own code readability 
  {
    return name.compare(vertex.name) < 0;
  }
};

void badData(string fileName);
void validFile(int argc);
void buildGraph(Graph<string>&airGraph, string fileName, vector<VertexType> &vertices );
void printGraphInput();
void dijkstra(Graph<string>&airGraph,vector<VertexType> vertices);
void printTable(vector<VertexType> vertices );
void determineDistance(Graph<string>& airGraph, vector<VertexType>& vertices, int mark, Queue<string>& connector);
bool markedPoints(vector<VertexType> vertices);
void printDijkstraRow(const VertexType&vertex);
int minValue(vector<VertexType> vertices);
string validVertex(vector<VertexType> vertices);

int main( int argc, char* argv[] )
{
  string fileName;
  Graph<string>airGraph;
  vector<VertexType> vertices;
  
  validFile(argc);
  
  fileName = argv[1];
  
  buildGraph(airGraph, fileName, vertices);
  
  printTable(vertices);
  
  dijkstra(airGraph, vertices);
  
  return 0;
}

void badData(string fileName) // takes in data from a file 
{
  ifstream infile;
  infile.open(fileName.c_str());
  if(!infile)
  {
    cout << " The File Name you Entered Does Not Exist in The Current Directory. Try Again. " << endl;
    infile.close();
    exit(1);
  
  }
  infile.close();
} 

void validFile(int argc)
{
  if(argc == 2)
  {
    return;
  }
  else
  {
    cout << "Invalid File Format Entered." << endl;
    exit(1);
  }

}
string validVertex(vector<VertexType> vertices)
{
  string start;
  bool valid = false;
  
    cout << "\n Enter a Starting Vertex: ";
    getline(cin, start);
    for( int i  = 0; i < vertices.size(); i++)
    {
      if(start == vertices[i].name)
      {
        valid = true;
      }
    }
    while(!valid)
  {
    cout << "Starting Location Does Not Exist." << endl;
    cout << "\n Please Enter a New Starting Vertex: ";
    getline(cin, start);
    for( int i  = 0; i < vertices.size(); i++)
    {
      if(start == vertices[i].name)
      {
        valid = true;
      }
    }
  }
  return start;
}

void buildGraph(Graph<string>&airGraph, string fileName, vector<VertexType> &vertices) // builds graph & stores vertices into their proper container 
{

  badData(fileName); // checks for a valid file in our current directory
  
  ifstream infile;
  vector<VertexType> edges;
  string curr;
  
  
  infile.open( fileName.c_str() );
  
  while( getline(infile,curr) ) // building a vector full of edges to be added to the graph later
  {
    string token;
    vector<string> line;
    stringstream ss(curr);
    while( getline(ss,token,';') )
    {
      line.push_back(token);
    }
    VertexType temp = { //temporary Vertex struct made and pushed onto the edges vector
    line[0], false , atoi( line[2].c_str() ), line[1]
    }; 
    edges.push_back(temp);  
  }
  
  VertexType first = { // created manually to avoid not being found later and will always be unique
  edges[0].name, false, INT_MAX, "" // may need to fix to "" or NULL later if issues arise
  };
  vertices.push_back(first);
  
  for(int i = 0; i < edges.size(); i++)  // duplicate checks for unique vertices in both the origin and destination categories
  {
    bool origin,dest = false;
    
    for(int j = 0; j < vertices.size(); j++)
    {
      if(!origin && edges[i].name == vertices[j].name)
      {
        origin = true;
      }
    }
    if(!origin)
    {
      VertexType start = {
      edges[i].name, false, INT_MAX, ""
      }; 
      vertices.push_back(start);
    }
    
    for(int k = 0; k < vertices.size(); k++)
    {
      if(!dest && edges[i].previous == vertices[k].name)
      {
        dest = true;
      }
    }
    if(!dest)
    {
      VertexType end = {
      edges[i].previous, false, INT_MAX, ""
      }; 
      vertices.push_back(end);
    }
    
  } 
  
 
  
  for(int l = 0; l < vertices.size(); l++) // Adding the Vertices and Edges to the Graph
  {
    airGraph.AddVertex(vertices[l].name);
  }
  for( int m = 0; m < edges.size(); m++)
  {
    airGraph.AddEdge(edges[m].name, edges[m].previous, edges[m].distance);
  }
    
  
  
  
}


void dijkstra(Graph<string>&airGraph,vector<VertexType> vertices)
{
  string start = validVertex(vertices);
  bool terminate = false;
  int mark = -1;
  while(mark == -1)
  {
    for( int i = 0; i < vertices.size(); i++)
    {
      if(vertices[i].name == start)
      {
        mark = i;
      }
    }
    cout << endl;
  }
  //vertices[mark].name = start;
  vertices[mark].marked = true;
  vertices[mark].distance = 0;
  vertices[mark].previous = "N/A";
  airGraph.MarkVertex(vertices[mark].name);
  printf("\n %40s %40s %40s \n", "Vertex", "Distance", "Previous");
  printDijkstraRow(vertices[mark]); 
                                                // okay to here
  while(!markedPoints(vertices) && !terminate )
  {
    Queue<string>connector;
    airGraph.GetToVertices(vertices[mark].name,connector);
    determineDistance(airGraph,vertices,mark,connector);
    int minIndex = minValue(vertices);
    if(minIndex != -1)
    {
      vertices[minIndex].marked = true;
      airGraph.MarkVertex(vertices[minIndex].name);
      mark = minIndex;
      printDijkstraRow(vertices[mark]);
      
    } 
    else
    {
      terminate = true;
    } 
    
  } 


  if(terminate == true)
  {
    while( !markedPoints(vertices) ) 
    {
      for(int i = 0; i < vertices.size(); i++)
      {
        if(!vertices[i].marked)
        {
          airGraph.MarkVertex(vertices[i].name);
          vertices[i].marked = true;
          vertices[i].distance = -1;
          vertices[i].previous = "N/A";
          printDijkstraRow(vertices[i]);
        }
        cout << endl;
      }
    }
  } 
}

void printTable(vector<VertexType> vertices )
{ 

   sort(vertices.begin(), vertices.end()); // Sorting the vector
   
  cout << "^^^^^^^^^^^^^^^^     Dijkstra's Algorithm     ^^^^^^^^^^^^^^^^" << endl;
  cout << "A Weighted Graph Has Been Built For These " << vertices.size() << " Cities : " << endl;
  for(int i = 0; i < vertices.size(); i++)
  {
    if(i != 0 && i%3 == 0)
    { 
      cout << setw(20) << vertices[i].name << endl;
    } 
    
    else
    {
       cout << setw(20) << vertices[i].name;
    }
    
      
    
  }
  cout << endl;
  
}

bool markedPoints(vector<VertexType> vertices)
{
  for(int i = 0; i < vertices.size(); i++)
  {
    if(!vertices[i].marked)
    {
    return false;
    }
  }
  return true;
  
}



void determineDistance(Graph<string>& airGraph, vector<VertexType>& vertices, int mark, Queue<string>& connector)
{
  
  while( !connector.isEmpty() )
  {
    string next = connector.dequeue();
    int loc = -1;
    
    for(int i = 0; i<vertices.size() && i == -1; i++)
    {
      if(vertices[i].name == next)
      {
        loc = i;
      }
    }
    int newDist = airGraph.WeightIs(vertices[mark].name, vertices[loc].name); // seg fault here, does not like taking in two name strings from struct
    if(vertices[loc].distance >  newDist + vertices[mark].distance && !vertices[loc].marked)
    {
      vertices[loc].distance = newDist + vertices[mark].distance;
      vertices[loc].previous = vertices[mark].name;
    }
    
  }
}



void printDijkstraRow(const VertexType&vertex)
{
  if(vertex.distance == -1)
  {
    printf("\n %40s %40s %40s \n", vertex.name.c_str(), "N/A", vertex.previous.c_str());
  }
  else
  {
    printf("\n %40s %40s %40s \n", vertex.name.c_str(), vertex.distance, vertex.previous.c_str());
  }
}

int minValue(vector<VertexType> vertices)
{
  int max = INT_MAX - 1;
  int min;
  
  for(int i = 0; i < vertices.size(); i++)
  {
    if(!vertices[i].marked && vertices[i].distance < max)
    {
      max = vertices[i].distance;
      min = i;
    } 
  }
  return min; 
  
}


