#include <iostream>
using namespace std;
void extremearray(int arr[], int size)
{
    int brr[size];
    int i = 0;
    for (int left = 0, right = size - 1; left <= right; left++, right--)
    {
        // cout<<arr[left]<<endl;
        // cout<<arr[right]<<endl;
        brr[i] = arr[left];
        brr[i + 1] = arr[right];

        i = i + 2;
    }
    for (int i = 0; i < size; i++)
    {
        cout << brr[i] << endl;
    }
}
int main()
{
    int arr[] = {10, 2, 4, 5, 9, 8, 30, 12, 45};
    int size = 9;
    extremearray(arr, size);
    return 0;
}