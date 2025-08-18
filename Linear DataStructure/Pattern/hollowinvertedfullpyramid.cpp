#include<iostream>
using namespace std;
int main()
{
    int i,j,n;
    cin>>n;

    for(i=n-1;i>=0;i--)
        {   
          int k=n-i;//important line 
            for(j=0;j<n;j++)
             {
                if((i==n-1 || j==0 || i==j))
                {
                    cout<<k<<" ";
                    
                }
                
                else
                    cout<<" "<<" ";
                    k++;
             }  
                     
             cout<<endl;
             
             
           
        }
        return 0;
}