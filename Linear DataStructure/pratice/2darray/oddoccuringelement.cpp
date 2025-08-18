#include <iostream>
using namespace std;
int oddelement(int *arr, int &n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (s == e)
            return s;
        if (mid & 1)
        {
            if (arr[mid] == arr[mid + 1])
                e = mid - 1;
            else if (arr[mid] == arr[mid - 1])
                s = mid + 1;
            else
                return mid;
        }
        else
        {
            if (arr[mid] == arr[mid + 1])
                s = mid + 2;
            else if (arr[mid] == arr[mid - 1])
                e = mid - 2;
            else
                return mid;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}
int main()
{
    int arr[] = {3, 3, 4, 4, 15, 15, 7, 7, 9, 9, 10};
    int size = sizeof(arr) / sizeof(int);
    int ans = oddelement(arr, size);
    if (ans == -1)
        cout << "Element is Not found" << endl;
    else
        cout << "Element is Found:" << arr[ans] << endl;
}