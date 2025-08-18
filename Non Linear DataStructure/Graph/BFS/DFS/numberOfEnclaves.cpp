class Solution {
private:
    int solveUsingBFSRevision(vector<vector<int>>& grid,  vector<vector<bool>>& vis, int row, int col){
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col] = true;
        bool checkBoundry = false;
        int land = 1;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        while(!q.empty()){
            pair<int, int> cordinates = q.front();
            q.pop();
            int X = cordinates.first;
            int Y = cordinates.second;

            if(X == grid.size()-1 || Y == grid[0].size()-1 || X == 0 || Y == 0) {
                checkBoundry = true;
            }
            for(int i=0;i<4;i++){
                int newX = X + dx[i];
                int newY = Y + dy[i];

                if(newX < grid.size() && newY < grid[0].size() && newX >= 0 && newY >= 0 &&
                grid[newX][newY] == 1 && !vis[newX][newY]){
                    vis[newX][newY] = true;
                    q.push({newX, newY});
                    land++;
                }
            }
        }

        return checkBoundry == true ? 0 : land;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {

        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    ans += solveUsingBFSRevision(grid, vis, i, j);
                }
            }
        }   
        return ans;
    }
};