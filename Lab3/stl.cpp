#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void Initialize(vector<int> &v);
void Print(vector<int> v);
void Reverse(vector<int> &v);

int main()
{
  stack <string> s1,s2;
  
  s1.push("Hi there");
  s2.push("Bush's Baked Beans");
  
  if(s1.size() < s2.size())
  {
    cout << "s1 is less than s2" << endl;
  }
  else if(s2.size() < s1.size())
  {
     cout << "s2 is less than s1" << endl;
  }
  else
  {
    cout << "s1 is equal to s2" << endl;
  }
  
  vector <int> v;
  Initialize(v);
  Print(v);
  cout << endl;
  Reverse(v);
  Print(v);
  cout << endl;
  sort(v.begin(), v.end());
  Print(v);
  cout << endl;
  
  return 0;
}

void Initialize(vector<int> &v)
{
  int input;
  for( int i=0; i < 5; i++)
  {
  
    cout << "Please Enter Vector Values: ";
    cin >> input;
    v.push_back(input);
  
  }
}

void Print(vector<int> v)
{
  for (int i =0; i < v.size(); i++)
  {
    cout << v.at(i) << " ";
  }
}

void Reverse(vector<int> &v)
{
  reverse(v.begin(),v.end());
}