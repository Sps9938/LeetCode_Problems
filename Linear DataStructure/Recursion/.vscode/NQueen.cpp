#include <iostream>
#include<unordered_map>
#include <vector>
using namespace std;

unordered_map<int,bool> rowcheck;
unordered_map<int,bool> leftButoomcheck;
unordered_map<int,bool> leftUppercheck;

void PrintMyQueenPlaced(vector<vector<char>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool isSafe(vector<vector<char>> &board, int row, int col, int n)
{
    if(rowcheck[row]== true)
        return false;
    if(leftButoomcheck[row+col]== true)
        return false;
    if(leftUppercheck[n-1+col-row]== true)
        return false;

    return true;

    // int i = row;
    // int j = col;
    // // for check, if queen has placed or not
    // // 1. leftrow check
    // while (j >= 0)
    // {
    //     if (board[i][j] == 'Q')
    //         return false;
    //     j--;
    // }
    // // 2. topleftdigonal check
    // i = row;
    // j = col;
    // while (j >= 0 && i >= 0)
    // {
    //     if (board[i][j] == 'Q')
    //         return false;
    //     i--;
    //     j--;
    // }
    // // 3. leftButtomdigonal check
    // i = row;
    // j = col;
    // while (j >= 0 && i < n)
    // {
    //     if (board[i][j] == 'Q')
    //         return false;
    //     i++;
    //     j--;
    // }

    // return true;
}
void throwRecursion(vector<vector<char>> &board, int col, int n)
{
    // baee case
    if (col >= n)
    {
        PrintMyQueenPlaced(board, n);
        cout<<endl;
        return;
    }
    // 1 case for one queen placed then it will handle by recursive call
    // here i dentoted for row
    for (int row = 0; row < n; row++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 'Q';
            rowcheck[row]=true;
            leftButoomcheck[row+col]=true;
            leftUppercheck[(n-1)+col-row]=true;
            // next call
            throwRecursion(board, col + 1, n);
            // we passed the reference of board so don't forget when you comeback backtracking should be performed
            board[row][col] = '-';
            rowcheck[row]=false;
            leftButoomcheck[row+col]=false;
            leftUppercheck[(n-1)+col-row]=false;
        }
    }
}
int main()
{
    int n;
    cout << "Enter the value of n" << endl;
    cin >> n;
    int row=n;
    int col = n;
    vector<vector<char>> board(row, vector<char>(col, '-'));
    // throwRecursion(board, col, n);//yehipe mai galt the col agar pass kar
    //dya mtalab aki bar mai base case hit ho gya
    throwRecursion(board, 0, n);

}