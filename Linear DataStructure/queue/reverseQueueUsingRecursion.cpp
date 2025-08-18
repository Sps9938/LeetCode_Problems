#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int> &q)
{
    //Base case
    if(q.empty())
        return;

    int frontElement=q.front();
    q.pop();
    reverseQueue(q);


    //backtracking
    q.push(frontElement);

}
int main()
{
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
    cout << "Reverse Queue is: " << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
   
    
    return 0;
}