#include<iostream>
using namespace std;
int main()
{
    int row,col;
    cin>>row>>col;
    int arr[row][col]={{1,1,1},{1,0,1},{1,1,1}};
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(arr[i][j]==0)
            {
                arr[i][j]=0;
                arr[j][i]=0;
            }
        }
        if(row!=col)
        {
            arr[row][col]=0;
        }
    }

}