#include <iostream>
using namespace std;
void sortarray(int ar[], int size)
{
    //sort array using two pointers
    // for(int left=0,right=size-1;left<=right;left++,right--)
    // {
    //     if(ar[left]>ar[right])
    //         swap(ar[left],ar[right])
    // }
    // sort array with swap method
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (ar[i] > ar[j])
                swap(ar[i], ar[j]);
        }
    }
    // after sort
    for (int i = 0; i < size; i++)
    {
        cout << ar[i] << endl;
    }
}
int main()
{
    int ar[] = {0, 1, 1, 1, 0, 1, 0, 1, 0, 0};
    int size = 10;
    sortarray(ar, size);
    return 0;
}