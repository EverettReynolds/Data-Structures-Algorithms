#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include "huffman.h"
using namespace std;

const int letterNum = 256; 
const int lineLength = 80;


void fileError(string fName);
void formatError();
void inputChecker(int argc, char *argv[]);
void treeCreation(string flag, string fileName);
void fileCreation(string fileName, int Letters[], HuffmanTree huff);
void printHelpMessage();
int main(int argc, char *argv[])
{
  
  if(argc <= 1)
  {
    cout << " No input has been entered. Aborting. " << endl;
  }
  else
  {
    inputChecker(argc,argv);
    
  }
  
  return 0;
}


void inputChecker(int argc, char *argv[])
{
  string flag;
  string fileName;
  ifstream infile;
  
  if(argc == 2)
  {
    flag = argv[1];
    if(flag == "--help")
    {
      printHelpMessage();
    }
    if(flag == "--t")
    {
      formatError();
    }
    else
    {
      
      fileName = argv[1];
      ifstream infile(fileName.c_str());
      if(!infile)
      {
        fileError(fileName);
      }
      flag = "N/A";
      infile.close();
      treeCreation(flag,fileName);
    }
   
  }
  if(argc == 3 )
  {
    flag = argv[1];
    if(flag == "--help")
    {  
       fileName = argv[2];
       
       ifstream infile(fileName.c_str());
      if(!infile)
      {
        fileError(fileName);
      }
      printHelpMessage();
    }
    if(flag == "--t")
    {
      fileName = argv[2];
       
       ifstream infile(fileName.c_str());
      if(!infile)
      {
        fileError(fileName);
      }
      infile.close();
      treeCreation(flag,fileName);
      
    }
    if(!infile)
    {
      fileName = argv[2];
      fileError(fileName);
    }
  }
  
} 
void treeCreation(string flag, string fileName)
{
  char ch,curr;
  HuffmanTree huff;
  int Letters [letterNum];
  
	for (char ch = char(0);  ch <= char(126);  ch++)
   {
	  Letters[ch] = 0;
   }
   ifstream infile(fileName.c_str());
   
   while(infile)
   {
     infile.get(curr);
     Letters[curr]++;
     
   }
   
   for (char ch = char(0);  ch <= char(126);  ch++)
   {
     if(Letters[ch] != 0)
     {
       huff.insert(ch, Letters[ch]);
     }
   }
   huff.build();
   if(flag == "--t")
   {
     huff.PrintTable();
     fileCreation(fileName,Letters,huff);
   }
   if(flag == "N/A")
   {
     fileCreation(fileName,Letters,huff);
   }
   if(flag != "N/A" && flag != "--t")
   {
     fileError(fileName);
   }
   
   
}

void fileCreation(string fileName, int Letters[], HuffmanTree huff)
{
  int charNum;
  double percent;
  char character;
  string encrypt;
  float bits1;
  float bits2;
  ifstream infile(fileName.c_str());
  string newFile = fileName + "m.zip";
  ofstream outFile(newFile.c_str());
  charNum = ((huff.numNodes() + 1)/2);
  outFile << charNum << endl;
  
  for (char ch = char(0);  ch <= char(126);  ch++)
  {
	  if  (Letters[ch] != 0)
    {
      outFile << int(ch) << " " << huff.GetCode(ch) << endl;
    }
  } 
  infile.get(character);
  while(infile)
  {
    bits2++;
    encrypt = encrypt + huff.GetCode(character);
    infile.get(character);
  } 
  bits1 = encrypt.length();
  outFile << encrypt;
  percent = ((1-(bits1/(bits2*8)))*100);
  cout << "File Sucessfully Compressed to" << " " << bits1 << " " << "Bits ( " << percent << " % Less)." << endl;
  
  infile.close();
  outFile.close(); 
} 
void fileError(string fName)
{
  cout << "Your Zip File " << fName << " does not exist. Aborting. " << endl;
  exit(1);
}

void formatError()
{
  cout << " You Have Input an Invalid File Format." << endl;
  cout << " Type `ZIP --help ` if you need more information. Aborting. " << endl;
  exit(1);
}

void printHelpMessage()
{
  ifstream help;
  string line;
  help.open("help");
  
  while( getline(help,line))
  {
    cout << help << endl;
  }
  help.close();
}
