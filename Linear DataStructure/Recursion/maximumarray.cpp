#include <iostream>
#include<vector>
#include <limits.h>
using namespace std;
int maxarray(int arr[], int size, int i, int &maxi)
{
    if (i >= size)
        return maxi;
    if (arr[i] > maxi)
        maxi = arr[i];
    maxarray(arr, size, i + 1, maxi);
    return maxi;
}
int minarray(int arr[], int size, int x, int &minu)
{
    if (x >= size)
        return minu;
    if (arr[x] < minu)
        minu = arr[x];
    minarray(arr, size, x + 1, minu);
    return minu;
}
void printarray(int arr[], int size, int i)
{
    if (i >= size)
        return;
    printarray(arr, size, i + 1);
    cout << arr[i] << " ";
}
vector<int> digitprint(int n,vector<int> &arr)
{
    if (n == 0)
        return arr;
    int value = n % 10;
    digitprint(n / 10,arr);
    arr.push_back(value);
    return arr;
}
int main()
{
    // int arr[] = {30, 40, 80, 20, 15};
    // int size = sizeof(arr) / sizeof(int);
    // int i = 0;
    // int x = 0;
    // int maxi = INT_MIN;
    // int minu = INT_MAX;
    // cout << "max element of an array is:" << maxarray(arr, size, i, maxi) << endl;
    // cout << "min element of an array is:" << minarray(arr, size, x, minu) << endl;
    // printarray(arr, size, i);
    int n = 647;
    vector<int> arr;
    vector<int> ans=digitprint(n,arr);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}