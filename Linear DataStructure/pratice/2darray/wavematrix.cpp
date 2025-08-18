#include <iostream>
#include <vector>
using namespace std;
void wavematrix(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    for (int j = 0; j < col; j++)
    {
        if ((j & 1) == 0)
        {
            int i = 0;
            while (i < row)
            {
                cout << matrix[i][j] << " ";
                i++;
            }
        }
        else
        {
            int i = row - 1;
            while (i >= 0)
            {
                cout << matrix[i][j] << " ";
                i--;
            }
        }
    }
}

int main()
{
    vector<vector<int>> matrix{
        {4, 5, 6, 3}, {6, 7, 8, 7}, {8, 9, 3, 5}};

    wavematrix(matrix);
    // for (int i = 0; i < matrix.size(); i++)
    // {
    //     for (int j = 0; j < matrix[i].size(); j++)
    //     {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}