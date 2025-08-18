#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution
{
public:
    vector<int> optimeizedsolution(int *A, int *B, int *C, int &n1, int &n2, int &n3)
    {
        vector<int> arr(0);
        set<int> different;
        int i = 0, j = 0, k = 0;
        while (i < n1 && j < n2 && k < n3)
        {
            if (A[i] == B[j] && B[j] == C[k])
            {
                // arr.push_back(A[i]);
                different.insert(A[i]);
                i++;
                j++;
                k++;
            }
            else if (A[i] > B[j])
                j++;
            else if (B[j] > C[k])
                k++;
            else
                i++;
        }
        for (int i : different)
        {
            arr.push_back(i);
        }
        return arr;
    }
};
int main()
{
    Solution s;
    int A[] = {1, 5, 10, 20, 40, 80};
    // int A[] = {3, 3, 3};
    int B[] = {6, 7, 20, 80, 100};
    // int B[] = {3, 3, 3};
    int C[] = {3, 4, 15, 20, 30, 70, 80, 120};
    // int C[] = {3,3,3};
    int n1 = sizeof(A) / sizeof(int);
    int n2 = sizeof(B) / sizeof(int);
    int n3 = sizeof(C) / sizeof(int);
    vector<int> v = s.optimeizedsolution(A, B, C, n1, n2, n3);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}