#include<iostream>
#include<limits.h>
using namespace std;
void array(int arr[4][4],int row,int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int minarray(int arr[4][4],int row,int col)
{
    
    int minans=INT_MAX; 
   
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(arr[i][j]<minans)
                minans=arr[i][j];
        }
        
    }
    return minans;
}
int maxarray(int arr[4][4],int row,int col)
{
    
     int maxans=INT_MIN;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(arr[i][j]>maxans)
                maxans=arr[i][j];
        }
        
    }
    return maxans;
}
void transeposematrix(int arr[4][4],int row,int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=i+1;j<col;j++){
            swap(arr[i][j],arr[j][i]);
            // cout<<arr[i][j]<<" ";
        }
        
    }
}
void rowsum(int arr[4][4],int row,int col)
{
    
    for(int i=0;i<row;i++)
    {
        int rowsum=0;
        for(int j=0;j<col;j++)
        {
            
            rowsum=rowsum+arr[i][j];
        }
        
        cout<<rowsum<<endl;
    }
}
void colsum(int arr[4][4],int row,int col)
{
    
    for(int i=0;i<col;i++)
    {
        int colsum=0;
        for(int j=0;j<row;j++)
        {
            
        colsum=colsum+arr[j][i];
        }
        
        cout<<colsum<<endl;
    }
}

int main()
{
    int arr[4][4]={
        {1,2,3,20},{5,6,7,8},{9,10,11,12},{13,14,15,16}
    };
    int row=4;
    int col=4;
    cout<<"Array of matrix is:"<<endl;
    array(arr,row,col);
     int min=minarray(arr,row,col);
     cout<<"Minimum element of an array is:"<<endl;
     cout<<min<<endl;;
     int max=maxarray(arr,row,col);
     cout<<"Maximum element of an array is:"<<endl;
     cout<<max<<endl;
     cout<<"After traspose of matrix is:"<<endl;
     transeposematrix(arr,row,col);
     array(arr,row,col);
     cout<<"Row sum  is:"<<endl;
     rowsum(arr,row,col);
     cout<<"Column sum is"<<endl;
     colsum(arr,row,col);

    return 0;
}