#include <iostream>
using namespace std;

class Queue
{
public:
    int front;
    int rear;
    int *arr;
    int size;
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int data)
    {
        if (rear == size)
        {
            cout << "Queue is overflow" << endl;
            return;
        }
        else
        {
            arr[rear++] = data;
        }
    }

    void pop()
    {
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
    }

    int getFront()
    {
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return arr[front];
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

    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    q.print();
    cout << endl;
    cout << q.getFront();
    cout << endl;
    q.pop();
    q.print();
    cout << endl;
    cout << q.getFront();
    cout << endl;
    q.pop();
    q.print();
    cout << endl;
    cout << q.getFront();
    q.pop();
    q.print();
    cout << endl;
    cout << q.getFront();
    q.pop();
    cout << endl;
    q.print();
    cout << endl;
    cout << q.getFront();

    return 0;
}