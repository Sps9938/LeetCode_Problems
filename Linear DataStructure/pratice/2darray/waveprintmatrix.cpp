#include <iostream>
using namespace std;
void wavematrix(int a[3][4], int row, int col)
{
    int j = 0;
    for (int k = 0; k < col; k++)
    {
        if (k % 2 == 0)
        {
            for (int i = 0; i < row; i++)
                cout << a[i][k] << "," << " ";
        }
        else
        {
            for (int i = row - 1; i >= 0; i--)
                cout << a[i][k] << "," << " ";
        }
    }
}
int main()
{
    int a[3][4] = {
        {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int row = 3, col = 4;
    wavematrix(a, row, col);
    return 0;
}