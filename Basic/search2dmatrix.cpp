#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int &target)
    {
        // for using linear search
        // T.C = O(n*m)

        // for (int i = 0; i < matrix.size(); i++)
        // {
        //     for (int j = 0; j < matrix[i].size(); j++)
        //     {
        //         if (target == matrix[i][j])
        //             return 1;
        //     }
        // }
        // return false;

        // for using binary search
        //T.C=O(m * log n)
        // int m = matrix.size();
        // int n = matrix[0].size();
        // int row = 0;
        // while (row < m)
        // {
        //     int s = 0;
        //     int e = n - 1;
        //     int mid = s + (e - s) / 2;
        //     while (s <= e)
        //     {
        //         if (target == matrix[row][mid])
        //             return 1;
        //         else if (target > matrix[row][mid])
        //             s = mid + 1;
        //         else if (target < matrix[row][mid])
        //             e = mid - 1;
        //         mid = s + (e - s) / 2;
        //     }
        //     row++;
        // }
        // return false;
        
        //optimized above code
        //T.C= O(m+logn)=O(m+n)
        int m = matrix.size();
        int n = matrix[0].size();
        int s = 0;
        int e = n - 1;
        int mid = s + (e - s) / 2;
        int row = 0;
        // cout<<m<<endl;
        while (row < m)
        {
            if (s == n || e == -1)
            {
                s = 0;
                e = n - 1;
                mid = s + (e - s) / 2;
                row++;
                // cout << row << endl;
            }
            else if (s > e)
            {
                s = 0;
                e = n - 1;
                mid = s + (e - s) / 2;
                row++;
                // cout << row << endl;
            }
            else if (target == matrix[row][mid])
                return 1;
            else if (target > matrix[row][mid])
                s = mid + 1;
            else if (target < matrix[row][mid])
                e = mid - 1;
            mid = s + (e - s) / 2;
        }
        return 0;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 35;
    cout << s.searchMatrix(matrix, target);
    return 0;
}