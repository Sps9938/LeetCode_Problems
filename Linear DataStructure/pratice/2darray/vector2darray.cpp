#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<vector<int>> arr(5,vector<int>(10,6));
    int row=5;
    int col=10;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    // vector<int>arr(5,-7);

}