#include<iostream>
using namespace std;
//righsift of an array
void shiftarray(int ar[],int size)
{
    int n;
    cin>>n;
    for(int x=1;x<=n;x++)
    {
        for(int i=size-1;i>0;i--)
        {
            swap(ar[i],ar[i-1]);
        }
    }
}
int main()
{
    int ar[]={10,20,30,40,50,60};
    int size=6;
    shiftarray(ar,size);
    for(int i=0;i<size;i++)
    {
        cout<<ar[i]<<endl;
    }
    return 0;
}