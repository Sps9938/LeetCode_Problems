#include <iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueue(queue<int> &q)
{
    stack<int> s;
    while(!q.empty())
    {
        int element=q.front();
        s.push(element);
        q.pop();
    }

    while(!s.empty())
    {
        int element=s.top();
        q.push(element);
        s.pop();
    }
}
int main() {
  queue<int> q;
  q.push(3);
  q.push(2);
  q.push(8);
  q.push(5);
  q.push(7);
  q.push(10);
  q.push(15);
  q.push(12);

  reverseQueue(q);
  cout<<"Reverse Queue is: "<<endl;
  while(!q.empty())
  {
    cout<<q.front()<<" ";
    q.pop();
  }


  
  return 0;
}