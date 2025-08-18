#include <iostream>
using namespace std;
class kqueue
{
public:
    int *arr, *next, *front, *rear;
    int freespot, k, n;
    kqueue(int n, int k)
    {
        freespot = 0;
        this->n = n;
        this->k = k;
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];
        // count = new int[k];

        for (int i = 0; i < n; i++)
        {
            if (i == n - 1)
                next[i] = -1;
            else
                next[i] = i + 1;
        }
        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }
        // for (int i = 0; i < k; i++)
        // {
        //     count[i] = 0;
        // }
    }

    void push(int data, int qi)
    {
        // overflow
        // if (count[qi] == k)
        // {
        //     cout << qi << "->queue is overflow, can't insert" << endl;
        //     return;
        // }
        if (freespot == -1)
        {
            cout << "Queue is overflow, can't insert" << endl;
            return;
        }
        // find index
        int index = freespot;
        // update freespot
        freespot = next[index];

        if (front[qi] == -1)
        {
            front[qi] = index;
        }
        else
        {
            // link the previous element to current element
            next[rear[qi]] = index;
        }

        // update the next[index]
        next[index] = -1;

        // update rear
        rear[qi] = index;

        // // update the count
        // count[qi]++;

        // insert into array
        arr[index] = data;
    }
    void pop(int qi)
    {
        // check empty condition
        if (front[qi] == -1)
        {
            cout << qi + 1 << " queue is empty, can't remove" << endl;
            // count[qi] = 0;
            return;
        }
        int index = front[qi];
        front[qi] = next[index];

        if (front[qi] == -1)
        {
            rear[qi] = -1;
        }
        next[index] = freespot;
        freespot = index;
        arr[index] = -1;
    }
    int getFront(int qi)
    {
        if (front[qi == -1])
            return -1;
        return arr[front[qi]];
    }
    int getBack(int qi)
    {
        if (rear[qi] == -1)
            return -1;
        return arr[rear[qi]];
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
    ~kqueue()
    {
        delete[] arr;
        delete[] next;
        delete[] front;
        delete[] rear;
        // delete[] count;
    }
};
int main()
{
    kqueue kq(8, 3);
    kq.push(5, 0);
    kq.push(10, 0);
    kq.push(15, 1);
    kq.push(20, 1);
    kq.push(30, 0);
    kq.push(40, 0);
    kq.push(80, 2);
    kq.push(90, 2);

    kq.pop(0);
    kq.pop(0);
    kq.pop(0);
    kq.pop(0);
    kq.pop(1);
    kq.pop(1);
    kq.pop(2);
    kq.pop(2);

    kq.push(100, 1);
    kq.push(200, 0);
    kq.push(300, 0);
    kq.print();

    cout << endl;
    cout << endl;
    cout << "Front Element of" << " 1st queue is: " << kq.getFront(0);
    cout << endl;
    cout << endl;
    cout << "Back Element of" << " 1st queue is: " << kq.getBack(0);
    cout << endl;
    cout << endl;
    cout << "Front Element of" << " 2nd queue is: " << kq.getFront(1);
    cout << endl;
    cout << endl;
    cout << "Back Element of" << " 2nd queue is: " << kq.getBack(1);
    cout << endl;
    cout << endl;
    cout << "Front Element of" << " 3rd queue is: " << kq.getFront(2);
    cout << endl;
    cout << endl;
    cout << "Back Element of" << " 3rd queue is: " << kq.getBack(2);
    return 0;
}