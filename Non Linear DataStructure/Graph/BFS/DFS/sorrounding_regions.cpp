class Solution {
private:
    void solveUsingBFS(vector<vector<char>>& sorrounded, vector<vector<bool>>& vis, int row, int col){
        vis[row][col] = true;
        queue<pair<int, int>> q;
        q.push({row, col});
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        while(!q.empty()){
            pair<int, int> cordinates = q.front();
            q.pop();
            int X = cordinates.first;
            int Y = cordinates.second;

            for(int i=0;i<4;i++){
                int newX = X + dx[i];
                int newY = Y + dy[i];

                if(newX < sorrounded.size() && newY < sorrounded[0].size() && newX >= 0 && newY >= 0 &&
                sorrounded[newX][newY] == 'O' && !vis[newX][newY]){
                    vis[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }


    }
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<char>> sorrounded = board;
        int n = sorrounded.size();
        int m = sorrounded[0].size();
        vector<vector<bool>> vis(sorrounded.size(), vector<bool>(sorrounded[0].size()));
        //first row and last row
        for(int j = 0; j<m; j++){
            if(!vis[0][j] && sorrounded[0][j] == 'O'){
                solveUsingBFS(sorrounded, vis, 0, j);
            }
            if(!vis[n-1][j] && sorrounded[n-1][j] == 'O'){
                solveUsingBFS(sorrounded, vis, n-1, j);
            }
        }

        //first col and last col
        for(int i=0; i<n; i++){
            if(!vis[i][0] && sorrounded[i][0] == 'O'){
                solveUsingBFS(sorrounded, vis,  i, 0);
            }

            if(!vis[i][m-1] && sorrounded[i][m-1] == 'O'){
                solveUsingBFS(sorrounded, vis, i, m-1);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && sorrounded[i][j] == 'O') {
                    sorrounded[i][j] = 'X';
                }
            }
        }
        board.clear();
        board = sorrounded;
    }
};