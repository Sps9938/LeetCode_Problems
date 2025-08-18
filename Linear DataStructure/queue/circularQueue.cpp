#include <iostream>
using namespace std;
class CirQueue
{
public:
    int *arr;
    int size;
    int front;
    int rear;
    CirQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void push(int data)
    {
        // Overflow
        if ((front == 0 && rear == size - 1) || rear == front - 1)
        {
            cout << "Queue is Overflow" << endl;
            return;
        }
        // single element handle
        else if (front == -1)
        {
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        // circular condition
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = data;
        }
        // normal flow
        else
        {
            rear++;
            arr[rear] = data;
        }
    }
    void pop()
    {
        // empty condition
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
        }
        // single element handle
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        // circular condition
        else if (front == size - 1)
        {
            front = 0;
        }
        // normal flow
        else
        {
            arr[front] = -1;
            front++;
        }
    }
    int getFront()
    {
        if (front != -1)
            return arr[front];
        return -1;
    }
    int getBack()
    {
        if (rear != -1)
            return arr[rear];
        return -1;
    }

    bool isempty()
    {
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    CirQueue q(7);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);

    // // q.push(80);
    // cout<<"Back element of Queue is: "<<q.getBack()<<endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    // q.pop();

    // q.pop();
    // q.push(80);

    cout << "Back element of Queue is: " << q.getBack() << endl;
    if (q.isempty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }
    return 0;
}