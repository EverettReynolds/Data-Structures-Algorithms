#include <iostream>
#include "BinaryHeap.h"
using namespace std;

int main()
{
  BinaryHeap<char> PQ(50);
  
  for(char ch = 'A'; ch <= 'J'; ch++)
  {
    PQ.insert(ch);
  }
  PQ.deleteMin();
  
  cout << "Printing Left Subtree of The Root of The Heap : ";
  PQ.printLtSubtree();
  cout << endl;
  
  cout << "The Height of The Heap is: " << PQ.Height() << endl;
  
  cout << "The Maximum Value of The Heap is: "  << PQ.findMax() << endl;
  
  
  
  return 0;
}