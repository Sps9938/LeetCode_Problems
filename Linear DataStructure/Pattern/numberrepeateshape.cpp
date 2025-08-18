#include<iostream>
using namespace std;
int main()
{
    int i,j,n;
    cin>>n;
    int k=2*n-1;
    for(i=0;i<n;i++)
        {
            
            for(j=0;j<2*n-1;j++)
            {
            //    if(i==0 && j==0)
            //     cout<<i+1;
            //     else if(i!=0 && i>=j)
            if(j%2!=0 && j<=2*i-1 && i!=0)
                cout<<"*";
            else if(j%2==0 && 2*i>=j)
                cout<<i+1;
            else
                cout<<" ";
                
               
            }
            cout<<endl;
        }
        return 0;
}