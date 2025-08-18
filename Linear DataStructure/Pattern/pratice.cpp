#include<iostream>
using namespace std;
int main()
    {
        int i,j,n;
        cin>>n;
        int k=2*n-1;
        for(i=0;i<n;i++)   
         {
            for(j=0;j<k;j++)
            {
                if(i<=j && j<=((k-1)-i) && j%2==0 && i%2==0)
                    cout<<"*";
                else if( i<=j && j<=((k-1)-i)  && j%2!=0 && i%2!=0)
                    cout<<"*";
                else 
                 cout<<" ";

            }
            cout<<endl;
        }
    }