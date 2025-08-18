//1st trial
#include <iostream>
using namespace std;
class Solution
{
public:
    void bubblesortalgorighm(int *arr, int &n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
            }
        }
    }

    void selectionsortalgorighm(int *arr, int &n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int minindex = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[minindex] > arr[j])
                    minindex = j;
            }
            swap(arr[minindex], arr[i]);
        }
    }
    void insertionsortalgorithm(int *arr, int &n)
    {
        int j = 0;
        while (j < n - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                j = 0;
            }
            else
                j++;
        }
    }
};
int main()
{
    Solution s;
    int arr[] = {40, 5, 3, 7, 15, 20, 30, 60};
    int n = sizeof(arr) / sizeof(int);
    // s.bubblesortalgorighm(arr, n);
    s.insertionsortalgorithm(arr, n);
    cout << "After swapping the array is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

//2nd trial
/*
#include <iostream>
using namespace std;
void selectionsort(int *arr,int &n)
{
  int j=0;
  for(int i=0;i<n-1;i++)
  {
    int minindex=i;
    for( j=i+1;j<n;j++)
    {
      if(arr[j]<arr[minindex])
        minindex=j;
    }
    swap(arr[minindex],arr[i]);
  }
}
void inseriionsort(int *arr,int &n)
{
  for(int i=0;i<n-1;i++)
  {
    int j=i;
    while(j>=0 && j<n-1)
    {
      if(arr[j]>arr[j+1])
      {
        swap(arr[j],arr[j+1]);
       j--;
      }
      else 
        j++;

    }
  }
}

int main() {
  int n;
  cin>>n;
  int arr[10];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  selectionsort(arr,n);
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  return 0;
}
*/