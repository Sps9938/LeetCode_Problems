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


 void HeapSort(int arr[], int n){
    /*recursion
    if(n == 1) return;
    
    //swqp root with last node
    swap(arr[index], arr[n]);
    n = n-1;

    //arr[index] is in right postion or not
    Heeapify(arr,n, index);

    HeapSort(arr, n, index);

    */

    //itrative
    while( n!=1 ){
        swap(arr[1], arr[n]);
        n = n -1;


        Heeapify(arr, n, 1);

    }

 }

};


int main()
{

    Heap h;

    int arr[] = {-1, 12, 56, 43, 6, 78, 87, 5, 44, 3, 23, 32};
    int n = 11;
    h.BuidHeap(arr, n);
    cout<<"Beftore sorting Heap is: "<<endl;
    for(int i = 0; i <= n; i++){
        cout<<arr[i]<<" ";
    }
    


    h.HeapSort(arr, n);
    cout<<endl;
    cout<<"After sorting the Heap is: "<<endl;
     for(int i = 1; i <= n; i++){
        cout<<arr[i]<<" ";
    }
    // h.arr[1] = h.arr[h.size];
    // h.size = h.size -1;

    // cout<<endl;
  


    return 0;
}