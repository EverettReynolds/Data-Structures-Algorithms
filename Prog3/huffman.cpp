#include "huffman.h"
#include <iostream>
#include <queue>
using namespace std;

HuffmanTree:: HuffmanTree()
	: numChars(0), built(false) {}

void HuffmanTree:: insert(char ch, int weight) {
    HNode newNode = {ch, weight, -1, -1}; 
    built = false;
    nodes.push_back(newNode);
    numChars++;

}

bool HuffmanTree:: inTree(char ch) {

  return lookUp(ch) == ch;
  
}

int HuffmanTree:: GetFrequency(char ch) { //public

  return GetFrequency(lookUp(ch));
  
}

int HuffmanTree:: GetFrequency(int i) { //private
  return nodes[i].weight;
}

int HuffmanTree:: lookUp(char ch) {

  int index;
  
  
  for(int i = 0; i < numChars; i++)
  {
    if(nodes[i].ch == ch)
    {
      i = index;
      return index;
    }
  }
  return -1;
}

string HuffmanTree:: GetCode(char ch) { //public 

  GetCode(lookUp(ch));
  
}


string HuffmanTree:: GetCode(int i) { //private
  
  if(nodes[i].parent == 0)
  {
    return "";
  }
  else
  {
    return (GetCode(nodes[i].parent) + (char)(nodes[i].childType + '0'));
  }
}

void HuffmanTree:: PrintTable() {

  int madeNode = 1;
  cout << "\t ## ENCODING TABLE FOR ZIP FILE ## \n " << endl;
  cout << "\t Index\tChar\tWeight\tParent\tChildType " << endl;
  
  for(int i = 0; i < nodes.size(); i++)
  {
    if(nodes[i].ch == '\n')
    {
      cout << i << '\t' << "nl" << '\t' << nodes[i].weight << '\t' << nodes[i].parent << '\t' << nodes[i].childType << '\t' << endl;
    }
    if(nodes[i].ch == ' ')
    {
      cout << i << '\t' << "sp" << '\t' << nodes[i].weight << '\t' << nodes[i].parent << '\t' << nodes[i].childType << '\t' << endl;
    }
    if(nodes[i].ch == '\0')
    {
      if( nodes[i].childType == 2)
      {
        cout << i << '\t' << "T" << madeNode << "\t" << nodes[i].weight << "\t" <<  nodes[i].parent << "\t" << "N/A" << "\t" << endl;
        madeNode++;
      }
      else
      {
         cout << i << '\t' << "T" << madeNode << "\t" << nodes[i].weight << "\t" <<  nodes[i].parent << "\t" << nodes[i].childType << "\t" << endl;
         madeNode++;
      }
    }
    else
    {
      cout << i << "\t" << nodes[i].ch << "\t" << nodes[i].weight << "\t" << nodes[i].parent << "\t" << nodes[i].childType << "\t" << endl;
    }
  }
  
}

int HuffmanTree:: numNodes() {
  return numChars;
}

void HuffmanTree:: build() {
  
  int max = (2*numChars)-2;
  int first; // smallest value
  int second; // second smallest after first
  
  for( int i = 0; i < max; i++)
  {
    first = i;
    second = 0;
    
    if( second == first )
    {
      second++;
    }
    else if( nodes[second].parent != -1)
    {
      second++;
    }
    else if( nodes[i].parent == -1)
    {
      for(int j = 0; j < nodes.size(); j++)
      {
        if(nodes[j].parent == -1 && nodes[first].weight > nodes[j].weight)
        {
          first = j;
        }
      }
    }
    else
    {
      for(int k = 0; k < nodes.size(); k++)
      { 
        if(nodes[k].parent != -1 && k!= first)
        {
          second = k;
        }
        if(nodes[second].weight > nodes[k].weight)
        {
          second = k;
        }
        
      }
    }
    int totalWeight = nodes[first].weight  + nodes[second].weight;
    HNode newest = {'\0',totalWeight,-1,-1};
    nodes.push_back(newest);
    nodes[first].parent = nodes.size()-1;
    nodes[first].childType = 0;
    nodes[second].parent = nodes.size()-1;
    nodes[second].childType = 1;
  }
  nodes[nodes.size()-1].parent = 0;
  nodes[nodes.size()-1].childType = 2;
  built = true;



}
