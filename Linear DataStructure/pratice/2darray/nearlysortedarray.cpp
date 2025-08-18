#include <iostream>
using namespace std;
int nearlysortedarray(int *arr, int &n, int &target)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[mid - 1] == target)
            return mid - 1;
        else if (arr[mid] == target)
            return mid;
        else if (arr[mid + 1] == target)
            return mid + 1;
        else if (target > arr[mid])
            s = mid + 2;
        else if (target < arr[mid])
            e = mid - 2;
        mid = s + (e - s) / 2;
    }
    return -1;
}
int main()
{
    int arr[] = {20, 10, 30, 40, 60, 50, 70};
    int size = sizeof(arr) / sizeof(int);
    int target = 110;
    int ans = nearlysortedarray(arr, size, target);
    if (ans == -1)
        cout << "Element is Not Found" << endl;
    else
        cout << "Element is Found:" << ans << endl;
    return 0;
}