#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<vector<int>> brr;
        brr = matrix;//here we must copy the matrix otherwise you sholud follow push_back(data) operation but ,copy is more understable process
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 0)//travese check the zero element
                {
                    for (int row = 0; row < matrix[i].size(); row++)// need column size then increment//set zero for using i as a row and row as column size
                    {
                        brr[i][row] = 0;
                    }
                    for (int col = 0; col < matrix.size(); col++)//nee row size then increment//set zero for using j as a col and col as row size
                    {
                        brr[col][j] = 0;
                    }
                }
            }
        }
        matrix = brr;
    }
};
int main()
{
    vector<vector<int>> matrix =
        //     {1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
        {
            {0, 1}};//here when we take n*m matrix the we faced problem that set for col zero need another loop
    Solution s;
    s.setZeroes(matrix);
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
//the above code time complexcity is:
//O(n*m)->	The code has two nested loops iterating over the rows and columns of the matrix, resulting in a time complexity of O(n*m) where n is the number of rows and m is the number of columns in the matrix.