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
   void Heeapify(int arr[], int n, int i){

    int index = i;
    int leftIndex = 2*index;
    int rightIndex = 2*index+1;
    int largestIndex = index;

    if(leftIndex <= n && arr[largestIndex] < arr[leftIndex]){
        largestIndex = leftIndex;
    }

    if(rightIndex <= n && arr[largestIndex] < arr[rightIndex]){
        largestIndex = rightIndex;
    }

    if(largestIndex != index){
        swap(arr[largestIndex] , arr[index]);
        index = largestIndex;
        Heeapify(arr, n, index);
    }
   }

   void BuidHeap(int arr[], int n){
    for(int i = n/2; i>0; i-- ){
        Heeapify(arr, n, i);
    }

  
   }


 

};


int main()
{

    Heap h;

    int arr[] = {-1, 12, 56, 43, 6, 78, 87, 5, 44, 3, 23, 32};
    int n = 11;
    h.BuidHeap(arr, n);
    cout<<"Heapify tree is: "<<endl;
    for(int i = 0; i <= n; i++){
        cout<<arr[i]<<" ";
    }
    

    // h.arr[1] = h.arr[h.size];
    // h.size = h.size -1;

    // cout<<endl;
  


    return 0;
}