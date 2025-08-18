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
        front = -1;
        rear = -1;
    }
    void push(int data)
    {
        if(front == -1)
        {
            front=0;
        }
        if (rear >= size-1)
        {
            cout << "Queue is Overflow" << endl;
        }
        else
        {
            rear++;
            arr[rear] = data;
            
        }
    }
    void pop()
    {
        if ((front==-1 && rear == -1) || rear < front)
        {
            cout<<endl;
            cout << "Queue is empty" << endl;
            rear=-1;
            front=-1;
        }
        else
        {
            arr[front] = -1;
            front++;
           
        }
    }

    int getFront()
    {

        return arr[front];
    }

    int getSize()
    {
        
        if(front == -1 && rear == -1)
            return 0;
        else{
            return rear - front + 1;
        }
    }

    bool isEmpty()
    {

        if ((front == -1 && rear == -1) || rear < front)
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
    Queue q(10);

    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);
    q.push(25);
    q.push(30);
    q.push(35);

    while (!q.isEmpty())
    {
        cout << q.getFront() << " ";

        q.pop();
    }
    cout<<endl;
    if(q.isEmpty())
    {
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }
 
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