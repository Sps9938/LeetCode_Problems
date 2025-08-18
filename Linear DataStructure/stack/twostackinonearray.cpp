#include <iostream>
using namespace std;
class Stack
{
private:
    int *arr;
    int top1;
    int top2;
    int size;

public:
    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }
    void push1(int data)
    {
        cout << "Top1 is:" << top1 << endl;
        cout << "Top2 is:" << top2 << endl;

        if (top2 - top1 == 1)
        {
            cout << "Stack1 is Overflow" << endl;
        }
        else
        {
            top1++;
            arr[top1] = data;
        }
    }
    void pop1()
    {

        if (top1 == -1)
        {
            cout << "Stack1 is Underflow" << endl;
        }
        else
        {
            arr[top1] = 0;
            top1 = top1 - 1;
        }
        cout << "Top1 is:" << top1 << endl;
        cout << "Top2 is:" << top2 << endl;
    }
    void push2(int data)
    {
        cout << "Top1 is:" << top1 << endl;
        cout << "Top2 is:" << top2 << endl;
        if (top2 - top1 == 1)
        {
            cout << "Stack2 is Overflow" << endl;
        }
        else
        {
            top2--;
            arr[top2] = data;
        }
    }
    void pop2()
    {

        if (top2 == size)
        {
            cout << "Stack2 is Underflow" << endl;
        }
        else
        {
            arr[top2] = 0;
            top2 = top2 + 1;
        }
        cout << "Top1 is:" << top1 << endl;
        cout << "Top2 is:" << top2 << endl;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
int main()
{
    Stack s(10);
    s.push1(10);
    s.print();
    cout << endl;
    s.push1(20);
    s.print();
    cout << endl;
    s.push1(30);
    s.print();
    cout << endl;
    s.push1(40);
    s.print();
    cout << endl;
    s.push1(50);
    s.print();
    cout << endl;

    s.push2(100);
    s.print();
    cout << endl;
    s.push2(110);
    s.print();
    cout << endl;
    s.push2(120);
    s.print();
    cout << endl;
    s.push2(130);
    s.print();
    cout << endl;
    s.push2(140);
    s.print();
    cout << endl;

    s.pop1();
    s.print();
    cout << endl;
    s.pop1();
    s.print();
    cout << endl;
    s.pop1();
    s.print();
    cout << endl;
    s.pop1();
    s.print();
    cout << endl;
    s.pop1();
    s.print();
    cout << endl;

    s.pop2();
    s.print();
    cout << endl;
    s.pop2();
    s.print();
    cout << endl;
    s.pop2();
    s.print();
    cout << endl;
    s.pop2();
    s.print();
    cout << endl;
    s.pop2();
    s.print();
    cout << endl;
    s.pop1();
}