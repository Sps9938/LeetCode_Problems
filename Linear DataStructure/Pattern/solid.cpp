#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i,j;
    // for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<n;j++)
    //             {
    //                 if(j<n)
    //                     cout<<"*"<<" ";
    //             }
    //             cout<<endl;
    //     }
    for(i=0;i<n;i++)  
        {
            
               for(j=0;j<n;j++)
                {  
                     if(i==0 || i==n-1 || j==0 || j==n-1)
                         cout<<"*"<<" ";
                    else
                     cout<<" "<<" ";  
                }
                cout<<endl;
            
            // else
            // {
            //      for(int j=0;j<n;j++)
            //         {
            //             if(j==0 || j==n-1)
            //                 {
            //                     cout<<"*"<<" ";
            //                 }
            //             else
            //              cout<<" "<<" ";
            //         }
            //         cout<<endl;
            // }
        }
        return 0;
}