#include <iostream>
using namespace std;
// bool bi_search(int arr[] ,int &target,int size)
// {
//     int start=0,end=size-1;
//     while(start<=end)
//     {
//         int mid=start+(end-start)/2;
//         if(arr[mid]==target)
//             return true;
//         else if(arr[mid]>target)
//             end=mid-1;
//         else
//             start=mid+1;
//     }
//     return false;
// }
int  binary_search(int arr[], int target, int size, int s, int e)
{
    if (s > e)
        return -1;
    int mid = s + (e - s) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return binary_search(arr, target, size, s, mid - 1);
    else
        return binary_search(arr, target, size, mid +1, e);
}
int main()
{
    int arr[] = {3, 9, 10, 50, 70};
    int target = 7;
    int size = sizeof(arr) / sizeof(int);
    // if(bi_search(arr,target,size))
    //     cout<<"Target is found"<<endl;
    // else
    //     cout<<"Target is not found"<<endl;
    int s = 0;
    int e = size - 1;
    int ans=binary_search(arr, target, size, s, e);
    if (ans!=-1)
        cout << "Target is found at:" <<ans<< endl;
    else
        cout << "Target is not found" << endl;
    return 0;
}