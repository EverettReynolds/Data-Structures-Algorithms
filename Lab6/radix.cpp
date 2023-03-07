#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <bits/stdc++.h> 
using namespace std;

int maxElemLength(const vector<int>& v);
int GetDigit(int number, int k);
vector<queue<int> > ItemsToQueues(const vector<int>& L, int k);
vector<int> QueuesToArray(vector<queue<int> >& QA, int numVals);
void RadixSort(vector<int>& L, int numDigits);
void PrintVector(const vector<int>& L);
string to_string(int i);

int main()
{
  vector<int>L;
  L.push_back(380);
  L.push_back(95);
  L.push_back(345);
  L.push_back(382);
  L.push_back(260);
  L.push_back(100);
  L.push_back(492);
  //380,95,345,382,260,100,492
  
  cout << "Unsorted Vector: " << endl;
  PrintVector(L);
  cout << endl;
  RadixSort(L,maxElemLength(L));
  cout << "Sorted Vector: " << endl;
  PrintVector(L);
  cout << endl;
  return 0;
}

int maxElemLength(const vector<int>& v)
{
  /*int i =0;
  int max = *max_element(v.begin(),v.end());
  while(max > 0)
  {
    max = max/10;
    i++;
  }
  return i;*/
  
  int m = 0;
  string middle;
  for(int i = 0; i < v.size(); i++)
  {
    middle = to_string(v[i]);
    if(middle.length() > m)
    {
      m = middle.length();
    }
  }
  return m;
}
int GetDigit(int number, int k)
{
  int digit;
  for(int i = 0; i < k; i++)
  {
    number = number / 10;
    digit = number % 10;
  }
  return digit;
  
}
vector<queue<int> > ItemsToQueues(const vector<int>& L, int k)
{
  int number;
  vector<queue<int> > QA(10);
  for(int i = 0; i < L.size(); i++)
  {
    number = GetDigit(L[i],k);
    QA[number].push(L[i]);
  }
  return QA;
}
vector<int> QueuesToArray(vector<queue<int> >& QA, int numVals)
{
  int index,queueSize;
  vector<int>newList(numVals);
  for(int i = 0; i < QA.size(); i++)
  {
    queueSize = QA[i].size();
    for(int j = 0; j < queueSize; j++)
    {
      index++;    
      newList[index] = QA[i].front();
      QA[i].pop();
    }
  }
  return newList;
  
}
void RadixSort(vector<int>& L, int numDigits)
{
  vector<queue<int> > QA(10);
  for(int k = 0; k < numDigits; k++)
  {
    QA = ItemsToQueues(L,k);
    L = QueuesToArray(QA, L.size());
  } 
}
void PrintVector(const vector<int>& L)
{
  for(int i = 0; i < L.size(); i++)
  {
    cout << L[i] << " ";
  }
}
string to_string(int i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}