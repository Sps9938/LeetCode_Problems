#include<iostream>
using namespace std;
int main()
{
    int i,j,n,num;
    cin>>num;
    n=num/2;
    int k=n+1;
    // int l=2*n;// take another varibale
    for(i=n-1;i>=0;i--)
        {
            
            for(j=0;j<(2*n)+1;j++)
                {
                   if(i>=j && j!=n)
                     cout<<"*";
                    else if(k<=j)
                        cout<<"*";
                    else
                     cout<<" ";   
                }
                k++;
                cout<<endl;
        }
    for(i=0;i<n;i++)
        {
          
            for(j=0;j<(2*n)+1;j++)
                {
                   if(i>=j && j!=n)
                     cout<<"*";
                    else if(j>=k-1)
                        cout<<"*";
                    else
                     cout<<" ";   
                }
                k--;
                cout<<endl;
        }
}