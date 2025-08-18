#include<iostream>
using namespace std;
void printallpairs(int ar[],int size)
{   
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            for(int k=0;k<size;k++)
            {
                cout<<"("<<ar[i]<<","<<ar[j]<<","<<ar[k]<<")"<<endl;
            }
        }
    }
}
int main()
{
    int ar[]={1,2,3,4,5};
    int size=5;
    printallpairs(ar,size);
    return 0;

}