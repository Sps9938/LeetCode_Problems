#include <iostream>
using namespace std;
void addtwomatrix(int arr[3][3], int brr[3][3], int crr[3][3], int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            crr[i][j] = arr[i][j] + brr[i][j];
            cout << crr[i][j] << " ";
        }
        cout << endl;
    }
}
void subtwomatrix(int arr[3][3], int brr[3][3], int crr[3][3], int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            crr[i][j] = arr[i][j] - brr[i][j];
            cout << crr[i][j] << " ";
        }
        cout << endl;
    }
}
void multwomatrix(int arr[3][3], int brr[3][3], int crr[3][3], int row, int col)
{

    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {
            int sum = 0;
            for (int k = 0; k < col; k++)
            {

                sum = sum + (arr[i][k] * brr[k][j]);
            }
            crr[i][j] = sum;
            cout << crr[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int arr[3][3] = {
        {2, 3, 0}, {2, 6, 7}, {4, 8, 0}};
    int brr[3][3] = {
        {3, 0, -8}, {1, -5, 0}, {0, 4, 6}};
    int crr[3][3];
    int row = 3, col = 3;
    cout << "Add Two Matrix is:" << endl;
    addtwomatrix(arr, brr, crr, row, col);
    cout << "Sub Two Matrix is:" << endl;
    subtwomatrix(arr, brr, crr, row, col);
    cout << "Multiplay two matrix is:" << endl;
    multwomatrix(arr, brr, crr, row, col);
    return 0;
}