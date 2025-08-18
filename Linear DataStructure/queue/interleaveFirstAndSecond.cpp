#include <iostream>
#include <queue>
using namespace std;
void interleave(queue<int> &q, int size)
{
    queue<int> first;
    // queue<int> second;
    int count = 0;

    while (!q.empty())
    {
        int element = q.front();
        first.push(element);
        q.pop();
        count++;
        if(count == size/2)
            break;
    }

    // while (!q.empty())
    // {
    //     int element = q.front();
    //     second.push(element);
    //     q.pop();
    // }

    while (!q.empty() && !first.empty())
    {
        int first_element = first.front();
        q.push(first_element);
        first.pop();

        int second_element = q.front();
        q.push(second_element);
        q.pop();
    }
    //handle odd case if size is odd then one element has remain to push into queue
    if( size & 1)
    {
        int last_element=first.front();
        q.push(last_element);
        
    }
}
int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    // q.push(60);
    // q.push(70);
    // q.push(80);
    int size = q.size();
    interleave(q, size);
    cout << "The Inverleave of first and second is" << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}