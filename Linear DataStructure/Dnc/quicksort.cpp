#include<iostream>
using namespace std;
 void quickSort(int a[], int s, int e)
    {
        // code here
        if(s>=e)
            return ;
        int pivot=e;
        int i=s-1;
        int j=s;
        while(j<pivot)
        {
            if(a[j]<a[pivot])
                {
                    i++;
                    swap(a[i],a[j]);
                }
            j++;
        }
        i++;
        swap(a[i],a[pivot]);
        quickSort(a,s,i-1);
        quickSort(a,i+1,e); 
        
    }
    
    int main()
    {
        int a[]={8,5,10,9,7,6,15};
        int size=sizeof(a)/sizeof(int);
        cout<<"Before sort"<<endl;
        for(int i=0;i<size;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        quickSort(a,0,size-1);
        cout<<"After sort"<<endl;
         for(int i=0;i<size;i++)
        {
            cout<<a[i]<<" ";
        }

    }