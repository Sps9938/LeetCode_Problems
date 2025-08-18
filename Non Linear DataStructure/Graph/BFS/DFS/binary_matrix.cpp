class Solution {
private:
    void solveUsingBFS(vector<vector<int>>& mat, vector<vector<int>>& dist){
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> vis(mat.size(), vector<bool>(mat[0].size(), false));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j] == 0){
                    pair<int, int> cordinates = make_pair(i, j);
                    q.push({cordinates, 0});
                    vis[i][j] = true;
                }
            }
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();
            int X = frontNode.first.first;
            int Y = frontNode.first.second;
            int minDist = frontNode.second;

            dist[X][Y] = minDist;

            for(int i=0;i<4;i++){
                int newX = X + dx[i];
                int newY = Y + dy[i];

                if(newX < mat.size() && newY < mat[0].size() && newX >= 0 && newY >= 0 &&
                !vis[newX][newY] && mat[newX][newY] == 1){
                    vis[newX][newY] = true;
                    pair<int, int> cordinates = make_pair(newX, newY);
                    q.push({cordinates, minDist+1});
                } 
            } 
        }
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> dist(mat.size(), vector<int>(mat[0].size(), -1));
        solveUsingBFS(mat, dist);

        return dist;
    }
};