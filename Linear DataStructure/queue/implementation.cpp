#include <iostream>
using namespace std;
class Queue
{
public:
    int *arr;
    int size;
    int front, rear;

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
            cout << "Queue is Overflow" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }
    void pop()
    {
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }

    int getFront()
    {
        return arr[front];
    }

    int getSize()
    {
        return rear - front;
    }

    bool isEmpty()
    {
        if (front == rear)
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
    Queue q(7);

    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);
    q.push(25);
    q.push(30);
    q.push(35);
    q.push(80);
    q.pop();
    q.push(50);

    // while (!q.isEmpty())
    // {
    //     cout << q.getFront() << " ";
    //     q.pop();
    // }
    // cout << "Size of Queue is: " << q.getSize() << endl;

    // cout<<"Front element in Queue is: "<<q.getFront()<<endl;
    // if(q.isEmpty())
    // {
    //     cout<<"Queue is empty"<<endl;
    // }
    // else{
    //     cout<<"Queue is not empty"<<endl;
    // }
    return 0;
}