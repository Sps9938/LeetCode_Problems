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
            cout << "Queue is overflow" << endl;
        }
        // normal flow
        else
        {
            arr[rear] = data;
            rear++;
        }
    }
    void pop()
    {
        // empty
        if (rear == 0 || front == rear)
        {
            cout << "Queue is empty" << endl;
            front = 0;
            rear = 0;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
    }
    int getSize()
    {
        return rear - front;
    }
    void print(int n)
    {

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
    void swapQueue()
    {

        while (front < rear)
        {
            //rear is in out of bound ,rear=size;
            //sow if wants acess rear element we neeed write as like arr[rear-1]
            int temp = arr[front];
            arr[front] = arr[rear - 1];
            arr[rear - 1] = temp;
            // swap(arr[front],arr[rear-1]);
            front++;
            rear--;
        }
    }
};
int main()
{
    Queue q(8);
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(7);
    q.push(8);
    q.push(2);
    q.push(10);
    // q.push(5);


    cout << "Before sort element of Queue is:" << endl;
    int n = q.getSize();
    q.print(n);
    cout << endl;

    q.swapQueue();
    cout << "After sort the element of Queue is:" << endl;
    q.print(n);

    return 0;
}