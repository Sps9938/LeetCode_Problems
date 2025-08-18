#include <iostream>
#include <vector>
using namespace std;
bool isSafe(int maze[][2], int newx, int newy, int row, int col, vector<vector<bool>> &visited)
{
    // codition for out of bound
    // condidion for visited or not
    if (
        (newx >= 0 && newx < row) &&
        (newy >= 0 && newy < col) &&
        (maze[newx][newy] == 1) &&
        (visited[newx][newy] == false))
    {
        return true;
    }

    else
    {
        return false;
    }
}
void PrintActualPath(int maze[][2], int row, int col, int srcx, int srcy, string output, vector<vector<bool>> &visited)
{
    // base case
    if (srcx == row - 1 && srcy == col - 1)
    {
        cout << output << " ";
        return;
    }
    //mark visided
     visited[srcx][srcy] = true;
    // up
    int newx = srcx - 1;
    int newy = srcy;
    if (isSafe(maze, newx, newy, row, col, visited))
    {
        // visited[newx][newy] = true;
        // recursive call
        output.push_back('U');
        PrintActualPath(maze, row, col, newx, newy, output, visited);
        // backtracking
 

        output.pop_back();
    }

    // right
    newx = srcx;
    newy = srcy + 1;
    if (isSafe(maze, newx, newy, row, col, visited))
    {
        // visited[newx][newy] = true;
        // recursive call
        output.push_back('R');
        PrintActualPath(maze, row, col, newx, newy, output, visited);
        // backtracking
    

        output.pop_back();
    }

    // left
    newx = srcx;
    newy = srcy - 1;
    if (isSafe(maze, newx, newy, row, col, visited))
    {
        // visited[newx][newy] = true;
        // recursive call
        output.push_back('L');
        PrintActualPath(maze, row, col, newx, newy, output, visited);
        // backtracking
        output.pop_back();
       

        
    }
   

    // down
    newx = srcx + 1;
    newy = srcy;
    if (isSafe(maze, newx, newy, row, col, visited))
    {
        // visited[newx][newy] = true;
        // recursive call
        output.push_back('D');
        PrintActualPath(maze, row, col, newx, newy, output, visited);
        // backtracking
        

        output.pop_back();
    }
     visited[srcx][srcy]=false;
}
int main()
{
    int maze[][2]{
        {1,1},
        {1,1}
        };
    int srcx = 0;
    int srcy = 0;
    int row = 2;
    int col = 2;
    // for checking visited once not vist again
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    string output = "";
    if(maze[0][0]==0)
    {
        cout<<"Not Path Exist"<<endl;
    }
    else{
         PrintActualPath(maze, row, col, srcx, srcy, output, visited);
    }
   
}