#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int startrow = 0;
        int endcol = n - 1;
        int endrow = m - 1;
        int startcol = 0;
        int total_element = m * n;
        int count = 0;
        while (count < total_element)
        {
            //startrow ka liya
            for (int i = startcol; i <= endcol && count < total_element; i++)
            {
                ans.push_back(matrix[startrow][i]);
                count++;
            }
            startrow++;
            //end col ka liya
            for (int i = startrow; i <= endrow && count < total_element; i++)
            {
                ans.push_back(matrix[i][endcol]);
                count++;
            }
            endcol--;
            //end row ka liya
            for (int i = endcol; i >= startcol && count < total_element; i--)
            {
                ans.push_back(matrix[endrow][i]);
                count++;
            }
            endrow--;
            //start col ka liya
            for (int i = endrow; i >= startrow && count < total_element; i--)
            {
                ans.push_back(matrix[i][startcol]);
                count++;
            }
            startcol++;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> matrix = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans;
    ans = s.spiralOrder(matrix);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}