#include <iostream>
using namespace std;

void mergeTwoArray(int a[], int s, int e)
{
    int mid = (s + e) / 2;
    int lenleft = mid - s + 1;
    int lenright = e - mid;
    // create a left and right array
    int *left = new int[lenleft];
    int *right = new int[lenright];
    // copy from to the new left and right array on orignal array
    int k = s;
    for (int i = 0; i < lenleft; i++)
    {
        left[i] = a[k];
        k++;
    }

    // for right array copy
    k = mid + 1;
    for (int i = 0; i < lenright; i++)
    {
        right[i] = a[k];
        k++;
    }
    // now actual merge left array and right array
    int i = 0;
    int j = 0;
    // yahin pe galti hain aur ho gya
    int mainsize = s;
    // int size = lenleft + lenright;
    while (i < lenleft && j < lenright)
    {
        if (left[i] < right[j])
        {
            a[mainsize] = left[i];
            i++;
            mainsize++;
        }
        else
        {
            a[mainsize] = right[j];
            j++;
            mainsize++;
        }
    }
    // 1 cae-> left array exhaust but right array me element abhi bhi bache hai
    while (i < lenleft)
    {
        a[mainsize] = left[i];
        i++;
        mainsize++;
    }
    // 1 cae-> right array exhaust but right array me element abhi bhi bache hai
    while (j < lenright)
    {
        a[mainsize] = right[j];
        j++;
        mainsize++;
    }

    delete[] left;
    delete[] right;
}
void mergesort(int a[], int s, int e)
{
    // bae cae
    // if (s > e)
    //     return;
    if (s == e)
        return;
    // recurssive case
    int mid = (s + e) / 2;
    // for right case
    mergesort(a, s, mid);
    // for left case
    mergesort(a, mid + 1, e);
    // for merge two array
    mergeTwoArray(a, s, e);
}
int main()
{
    int a[] = {5, 2, 9, 8, 7, 6};
    int len = sizeof(a) / sizeof(int);

    // before mergesort
    for (int i = 0; i < len; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    mergesort(a, 0, len - 1);
    // after mergesort
    for (int i = 0; i < len; i++)
    {
        cout << a[i] << " ";
    }
}