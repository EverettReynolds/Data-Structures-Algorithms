#include <iostream>
#include <queue>
using namespace std;

void print(priority_queue <string> pq);

int main()
{
  priority_queue<string>pq;
  pq.push("Everett");
  pq.push("Michael");
  pq.push("Alec");
  pq.push("Mason");
  pq.push("Blake");
  pq.push("Joseph");
  pq.push("Devan");
  pq.push("Evan");
  pq.push("Brandon");
  pq.push("Matt");
  print(pq);
  return 0;
}
void print(priority_queue <string> pq)
{

  priority_queue <string> t = pq;
  
  while(t.size() != 0)
  {
    cout << t.top() << " ";
    t.pop();
  }
  
  cout << endl;
  
}