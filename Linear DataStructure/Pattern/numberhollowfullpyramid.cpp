#include<iostream>
using namespace std;
int main()
{
    int i,j,n;
    cin>>n;

    for(i=0;i<n;i++)
        {   
            for(j=0;j<n;j++)
             {
                if(i==n-1 || j==0 || i==j)
                    cout<<j+1<<" ";
                // else if(j==0 || i==j)
                //     cout<<j+1<<" ";
                else
                    cout<<" "<<" ";
             }             
             cout<<endl;
           
        }
        return 0;
}