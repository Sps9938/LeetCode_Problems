#include <iostream>
using namespace std;
class Seque
{
public:
    int *arr;
    int size;
    int front;
    int rear;
    Seque(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void push_rear(int data)
    {
        // Overflow
        if ((front == 0 && rear == size - 1) || rear == front - 1)
        {
            cout << "Queue is full,can't insert" << endl;
            return;
        }
        // single element
        else if (front == -1)
        {
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        // circurlar condition
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = data;
        }
        // normal condition
        else
        {
            rear++;
            arr[rear] = data;
        }
    }
    void push_front(int data)
    {
        // Overflow
        if ((front == 0 && rear == size - 1) || rear == front - 1)
        {
            cout << "Queue is full,can't insert" << endl;
        }
        // single element
        else if (front == -1)
        {
            front = 0;
            rear = 0;
            arr[front] = data;
        }
        // circurlar condition
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
            arr[front] = data;
        }
        // normal condition
        else
        {
            front--;
            arr[front] = data;
        }
    }

    void pop_front()
    {
        // empty
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
        }
        // single element
        else if (front == rear)
        {
            arr[front] = 0;
            front = -1;
            rear = -1;
        }
        // circular condition
        else if (front == size - 1)
        {
            arr[front] = 0;
            front = 0;
        }
        // noramal flow
        else
        {
            arr[front] = 0;
            front++;
        }
    }
    void pop_rear()
    {
        // empty
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
        }
        // single element
        else if (front == rear)
        {
            arr[rear] = 0;
            front = -1;
            rear = -1;
        }
        // circular condition
        else if (rear == 0)
        {
            arr[rear] = 0;
            rear = size - 1;
        }
        // noramal flow
        else
        {
            arr[rear] = 0;
            rear--;
        }
    }
    int getFront()
    {
        if (front != -1)
            return arr[front];
        else
            return -1;
    }
    int getBack()
    {
        if (front != -1)
            return arr[rear];
        else
            return -1;
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

    Seque q(6);
    q.push_rear(10);
    q.push_rear(20);
    q.push_rear(30);
    q.push_rear(40);
    q.push_rear(50);
    q.push_rear(60);

    // play whith array
    q.pop_front();
    q.pop_rear();

    q.pop_front();
    q.pop_rear();

    q.pop_front();
    q.pop_rear();

    q.push_front(100);
    q.push_rear(38);

    q.push_front(50);
    q.push_rear(76);
    // Overflow checking

    // q.push_front(100);
    //  q.push_rear(90);

    // if rear=front-1 then ,queue is overflow ,this case because of  circularQueue

    // q.pop_front();//now oth index has removed and front element is  1st index which value=20

    // q.push_rear(110);

    // cout<<q.getBack()<<endl;//now, oth index has filled  which value is 110

    // can i push in queue if queue is full ,check it
    //  q.push_front(120);
    //  q.push_rear(120);

    //

    // remonve eleent checking

    // cout << "Front element of Queue is: " << q.getFront() << endl;
    // cout << "Back element of Queue is: " << q.getBack() << endl;

    // q.pop_rear();
    // cout << endl;

    // cout << "Front element of Queue is: " << q.getFront() << endl;
    // cout << "Back element of Queue is: " << q.getBack() << endl;

    // q.pop_front();
    // cout << endl;

    // cout << "Front element of Queue is: " << q.getFront() << endl;
    // cout << "Back element of Queue is: " << q.getBack() << endl;

    // q.pop_front();
    // cout << endl;

    // cout << "Front element of Queue is: " << q.getFront() << endl;
    // cout << "Back element of Queue is: " << q.getBack() << endl;

    // q.pop_rear();
    // cout << endl;

    // cout << "Front element of Queue is: " << q.getFront() << endl;
    // cout << "Back element of Queue is: " << q.getBack() << endl;

    // q.pop_rear();
    // cout << endl;

    // cout << "Front element of Queue is: " << q.getFront() << endl;
    // cout << "Back element of Queue is: " << q.getBack() << endl;

    // // q.push_rear(80);
    // // cout << endl;

    // // cout << "Front element of Queue is: " << q.getFront() << endl;
    // // cout << "Back element of Queue is: " << q.getBack() << endl;

    // q.pop_rear();
    // cout << endl;
    q.print();
    cout << endl;
    cout << "Front element of Queue is: " << q.getFront() << endl;
    cout << "Back element of Queue is: " << q.getBack() << endl;

    return 0;
}
