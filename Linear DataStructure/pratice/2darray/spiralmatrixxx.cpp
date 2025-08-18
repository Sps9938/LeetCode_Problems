#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution
{
public:
    void spiralOrder(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int total_element = row * col;
        int sc = 0;
        int ec = col - 1;
        int sr = 0;
        int er = row - 1;
        int count = 0;

        vector<int> ans;
        while (count < total_element + 5)
        {
            for (int i = sc; i <= ec && count < total_element; i++)
            {
                ans.push_back(matrix[sr][i]);
                count++;
            }
            sr++;
            for (int i = sr; i <= er && count < total_element; i++)
            {
                ans.push_back(matrix[i][ec]);
                count++;
            }
            ec--;
            for (int i = ec; i >= sc && count < total_element; i--)
            {
                ans.push_back(matrix[er][i]);
                count++;
            }
            er--;
            for (int i = er; i >= sr && count < total_element; i--)
            {
                ans.push_back(matrix[i][sc]);
                count++;
            }
            sc++;
        }
    }
};
int main()
{
    Solution s;
    vector<vector<int>> spiral{
        {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}

    };
    s.spiralOrder(spiral);
    //   for(int i=0;i<ans.size();i++)
    //   {
    //     cout<<ans[i]<<" ";
    //   }

    return 0;
}