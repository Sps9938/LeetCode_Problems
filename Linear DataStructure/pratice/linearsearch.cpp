#include<iostream>
using namespace std;
int main()
{
    int arr[5]={2,4,6,8,10};
    int n=5;
    bool check=0;
    int target=9;
    for( int i=0;i<n;i++)
    {
        if(target==arr[i])
        {
            check=1;
            break;
        }
      
    }
     if(check==1)
     {
        cout<<"Target found";

     }
     else{
        cout<<"Target is not found";
     }
}