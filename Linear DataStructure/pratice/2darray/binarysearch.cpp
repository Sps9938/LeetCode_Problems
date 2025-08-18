#include <iostream>
using namespace std;
int binarysearch(int *arr, int &n, int &target)
{
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;
    while (start <= end)
    {
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            start = mid + 1;
        else if (arr[mid] > target)
            end = mid - 1;
        // mid update
        mid = (start + end) / 2;
    }
    return -1;
}
int fans = -1;
void firstoccouance(int *arr, int &n, int &target)
{
    int s = 0;
    int e = n - 1;
    int mid = (s + e) / 2;

    while (s <= e)
    {
        if (arr[mid] == target)
        {
            fans = mid;

            e = mid - 1;
        }
        else if (target > arr[mid])
        {
            s = mid + 1;
        }
        else if (target < arr[mid])
        {
            e = mid - 1;
        }
        mid = (s + e) / 2;
    }
    // return fans;
}
int lans = -1;
void lastoccouance(int *arr, int &n, int &target)
{
    int s = 0;
    int e = n - 1;
    // int mid = (s + e) / 2;
    int mid = (s + (e - s)) / 2;

    while (s <= e)
    {
        if (arr[mid] == target)
        {
            lans = mid;
            // count++;
            s = mid + 1;
        }
        else if (target > arr[mid])
        {
            s = mid + 1;
        }
        else if (target < arr[mid])
        {
            e = mid - 1;
        }
        mid = (s + e) / 2;
    }
    //    return lans;
}

int countnumbeofoccourance(int *arr, int &n, int target)
{
    firstoccouance(arr, n, target);
    lastoccouance(arr, n, target);
    int ans = (lans - fans) + 1;
    return ans;
}

int findmissingelement(int *arr, int &n)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        int diff = arr[mid] - mid;
        if (diff == 1)
            s = mid + 1;
        else
        {
            ans = mid;
            e = mid - 1;
        }
        // jo likhna hamesa bhulega
        mid = s + (e - s) / 2;
    }
    return ans + 1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 7, 8};
    int n = sizeof(arr) / sizeof(int);

    int ans = findmissingelement(arr, n);
    if (ans == 0)
        cout << "Element Not Found" << endl;
    else
        cout << "Missing element is:" << ans << endl;

    return 0;
}
