#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = i + 1; j < matrix[i].size(); j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // two pointer approach
        //  for (int i = 0; i < matrix.size(); i++)
        //  {
        //      int left = 0;
        //      int right = matrix[i].size() - 1;
        //      while (left < right)
        //      {
        //          swap(matrix[i][left], matrix[i][right]);
        //          left++;
        //          right--;
        //      }
        //  }
        // using revese method
        for (int i = 0; i < matrix.size(); i++)
        {
        reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
int main()
{
    Solution s;
    vector<vector<int>> matrix{
        {1, 2, 3}, {5, 6, 7}, {9, 10, 11}};
    s.rotate(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}