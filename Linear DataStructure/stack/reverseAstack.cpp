#include <iostream>
#include <stack>
using namespace std;
void insertButtom(stack<int> &s, int target)
{
    // base case
    if (s.empty())
    {
        s.push(target);
        return;
    }
    int top = s.top();
    s.pop();
    insertButtom(s, target);
    // backtracking
    s.push(top);
}
void reverseStack(stack<int> &s)
{
    // base case
    if (s.empty())
    {
        return;
    }
    int target = s.top();
    s.pop();
    reverseStack(s);
    // insertAtBuutom
    insertButtom(s, target);
}
int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    reverseStack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}