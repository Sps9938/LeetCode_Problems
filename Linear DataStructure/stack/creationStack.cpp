#include <iostream>
using namespace std;
class Stack
{
private:
    int *arr;
    int top;
    int size;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    // insert the element into the stack
    void push(int data)
    {
        if (top < size-1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "Stack is Overflow" << endl;
        }
    }
    // remove the element from the stack
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is Underflow,no element delete" << endl;
        }
        else
        {
            top = top - 1;
        }
    }
    // getting topmost element from the stack
    int getTop()
    {
        if (top == -1)
            cout << "Stack is empty" << endl;
        else
            return arr[top];
    }
    // getting size of a stack
    int getSize()
    {
        if (top == -1)
            return 0;
        else
            return top + 1;
    }
    // check stack is empty or not
    bool IsEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
};
int main()
{
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    while (!s.IsEmpty())
    {
        cout << s.getTop() << " ";
        s.pop();
    }
    cout << endl;
    cout << s.getSize();
    cout<<endl;
    s.pop();
}