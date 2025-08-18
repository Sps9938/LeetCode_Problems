#include <iostream>
using namespace std;
class Queue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }
    void push(int data)
    {
        // overflow
        if (front == 0 && rear == size)
        {
            cout << "Queue is Overflow" << endl;
        }
        // push data into Queue
        else
        {
            arr[rear] = data;
            rear++;
        }
    }
    void pop()
    {
        // check Queue is empty or not
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
                // it means Queue is empty , the entire process continue again

                front = 0;
                rear = 0;
            }
        }
    }
    int getSize()
    {
        return rear - front;
    }
    bool isEmpty()
    {
        if (rear == 0)
            return true;
        else
            return false;
    }
    int getFront()
    {
        if (front != rear)
            return arr[front];
        else
            return -1;
    }

    int getBack()
    {
        if (front != rear)
            return arr[rear - 1];
        else
            return -1;
    }
};
int main()
{
    Queue q(10);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    cout << "Back element of Queue is: " << q.getBack();

    // cout<<"Front element of Queue is: "<<q.getFront();
    // q.pop();
    // cout<<"Size of Quue is: "<<q.getSize();
    // q.pop();
    // cout<<endl;
    // cout<<"Size of Queue is: "<<q.getSize();
    // q.pop();
    // cout<<endl;
    // cout<<"Size of Queue is: "<<q.getSize();
    // q.pop();
    // cout<<endl;
    // cout<<"Size of Queue is: "<<q.getSize();
    // q.pop();
    // cout<<endl;
    // cout<<"Size of Queue is: "<<q.getSize();
    // q.pop();
    // cout<<endl;
    // cout<<"Size of Queue is: "<<q.getSize();
    // q.pop();
    // cout<<endl;
    // cout<<"Size of Queue is: "<<q.getSize();
    // cout<<endl;
    // if(q.isEmpty())
    //   cout<<"Queue is empty"<<endl;
    // else{
    //   cout<<"Queue is not empty"<<endl;
    // }

    return 0;
}