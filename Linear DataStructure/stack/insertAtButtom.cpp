#include <iostream>
#include <stack>
using namespace std;
void solve(stack<int> &s, int target)
{
    // base case
    if (s.empty())
    {
        s.push(target);
        return;
    }
    int top = s.top();
    s.pop();
    solve(s, target);
    // backtracking
    s.push(top);
}
void insertButtom(stack<int> &s)
{
    if (s.empty())
    {
        cout << "Stack is empty ,can't inseet at buttom" << endl;
    }
    int target = s.top();
    s.pop();
    solve(s, target);
}
int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    insertButtom(s);  
    // print
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}