#include<iostream>
using namespace std;\
void dynamicarray(int arr[],int size)
{
    cout<<"Array elements are:"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<&arr[i]<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        arr[i]=data;
    }
    dynamicarray(arr,n);
    return 0;
}