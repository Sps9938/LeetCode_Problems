#include <iostream>
using namespace std;
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // Function to check if array has 2 elements
    // whose sum is equal to the given value
    bool hasArrayTwoCandidates(int arr[], int n, int x)
    {
        // code here
        bool b = 0;
        // for (int i = 0; i < n-1; i++)
        //     {
        //        for(int j=i+1;j<n;j++)
        //        {
        //            if(arr[i]+arr[j]==x)
        //            {
        //               b=true;
        //               break;
        //            }
        //        }
        //     }
        int left = 0;
        int y = n - 1;
        while (y != 0)
        {
            int right = n - 1;
            while (left < right)
            {

                if (arr[left] + arr[right] == x)
                {
                    b = true;
                    break;
                }
                else
                {
                    right--;
                }
            }
            left++;
            y--;
        }
        return b;
    }
};
int main()
{
    Solution s;
    int arr[] = {1, 4, 45, 6, 10, 8};
    int n = 6;
    int x = 13;
    bool b = s.hasArrayTwoCandidates(arr, n, x);
    cout << b;
}
//{ Driver Code Starts.
