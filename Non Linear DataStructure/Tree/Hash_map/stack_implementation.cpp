#include <iostream>
using namespace std;
class Stack
{
public:
    int top;
    int *arr;
    int size;
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data)
    {
        top++;
        if (top == size)
        {
            cout << "Stack is Overflow" << endl;
            return;
        }
        else
        {
            arr[top] = data;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        else
        {
            arr[top] = -1;
            top--;
        }
    }

    int getBack()
    {
        if (top == -1)
        {
            return -1;
        }
        else
        {
            return arr[top];
        }
    }
    
    void print()
    {
        if (top == size)
            return;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
int main()
{
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    // st.push(60);
    st.print();
    cout << endl;
    cout << st.getBack();
    cout << endl;
    st.pop();
    st.print();
    cout << endl;
    cout << st.getBack();

    st.pop();
    cout << endl;
    st.print();
    cout << endl;
    cout << st.getBack();

    st.pop();
    cout << endl;
    st.print();
    cout << endl;
    cout << st.getBack();

    st.pop();
    cout << endl;
    st.print();
    cout << endl;
    cout << st.getBack();

    st.pop();
    cout << endl;
    st.print();
    cout << endl;
    cout << st.getBack();

    // cout<<endl;
    // st.pop();

    return 0;
}