#include<iostream>
#include<algorithm>
using namespace std;
void missingelement(int arr[],int n)
    {
        //method one
       //visiting approach 
    int index=0;
    while(index<n)
    {
        if( arr[index]!=arr[arr[index]-1])
            swap(arr[index],arr[arr[index]-1]);
        else
            index++;

    }
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=i+1)
            cout<<i+1<<" ";
    }    
//method two
//sorting & swap on proper position
// for(int i=0;i<n;i++)
// {
//     int brr=abs(arr[i]);
//     int index=brr-1;
    
//     if(arr[index]>0)
//         arr[index]=arr[index]*-1;
    
    
// }
// for(int i=0;i<n;i++)
// {
//     if(arr[i]>0)
//          cout<<i+1<<" ";
// }
}
int main()
{
    int arr[]={1,4,3,4,3,6};
    int n=sizeof(arr)/sizeof(int);
    missingelement(arr,n);
    return 0;
}
