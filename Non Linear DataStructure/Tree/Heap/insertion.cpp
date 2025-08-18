#include<iostream>
using namespace std;

class Heap
{
    public:
        int size;
        int arr[100];

    Heap(){
        size = 0;
    }
    void insert(int value){
        size = size+1;
        int index = size;
        //1st insert the value
        arr[index] = value;

        //2nd check value right position , placed or not

        while(index > 1)
        {
            int parentIndex = index/2;
            if(arr[index] > arr[parentIndex])
            {
                swap(arr[index] , arr[parentIndex]);
                index = parentIndex;
            }
            else{
                break;
            }
        }


    }
};


int main()
{

    Heap h;

    h.insert(100);
    h.insert(50);
    h.insert(60);
    h.insert(40);
    h.insert(30);
    h.insert(35);
    h.insert(20);
    
    h.arr[0]=-1;
    cout<<"Heap Tree is: "<<endl;
    for(int i=0;i<=h.size;i++){
        cout<<h.arr[i]<<" ";
    }

    h.insert(80);
    cout<<endl;
    cout<<"After inserting value 80 new Heap tree is: "<<endl;
     for(int i=0;i<=h.size;i++){
        cout<<h.arr[i]<<" ";
    }
    return 0;
}