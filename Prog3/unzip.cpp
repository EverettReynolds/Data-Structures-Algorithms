#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
using namespace std;

//void fileInput(ifstream infile);
//void translate();

int main(int argc, char *argv[])
{
  
  ifstream infile;
  ofstream outfile;
 // map<string, int> mainTable;
  
  infile.open(argv[1]);
  outfile.open("unzipped");
  //fileInput(ifstream infile); // I have no idea why I can't do seperate methods
  
  map<string, int> table; // Finding the amount of lines for translation
  string curLine;
  int lNum;
  getline(infile, curLine);
  stringstream ss (curLine);
  ss >> lNum;
  
  
  
  
  
  
  for(int i = 0; i < lNum; i++) // Map Creation
  {
    string search;
    int aNum;
    getline(infile,search);
    string ascii = search.substr(0, search.find(" "));
    stringstream entry(ascii);
    entry >> aNum;
    string newEntry = search.substr(search.find(" ")+1, search.length());
    table[newEntry] = aNum;
    
  }
  
  string flag;
  char symbol;
  char foundS;
  while(infile) // Finding and Outputting algorithm for unzipped file
  {
    
    if(table.find(flag) == table.end())
    {
      infile.get(symbol);
      flag = flag + symbol;
    }
    else
    {
      foundS = (char) table[flag];
      flag = "";
      outfile << foundS;
    }
  }
  
  cout << "File Has Been Sucessfully Inflated" << endl;
  infile.close();
  outfile.close();
  return 0;
}


/* void fileInput(ifstream infile)
{

  map<string, int> table;
  string curLine;
  int lNum;
  stringstream ss (curLine);
  getline(infile, curLine);
  ss >> lNum;
  cout << lNum;
  
  
  
  
  
  for(int i = 0; i < lNum; i++)
  {
    string search;
    int aNum;
    getline(infile,search);
    string ascii = search.substr(0, search.find(" "));
    stringstream entry(ascii);
    entry >> aNum;
    string newEntry = search.substr(search.find(" ")+1, search.length());
    cout << ascii << " " << newEntry << endl;
    table[newEntry] = aNum;
    
  }
 
 
 
}


void translate()
{
  
}
*/

