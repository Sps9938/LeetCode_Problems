class Solution {
private:
    int solveUsingBFS(vector<vector<int>>& grid, vector<vector<int>>& dist){
        queue<pair<pair<int, int>, int>> q;
        pair<int, int> cordinates = make_pair(0, 0);
        q.push({cordinates, 0});

        dist[0][0] = 0;

        int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
        int dy[] = {0, 0, -1, 1, -1, 1, 1, -1};
        while(!q.empty()){
            auto topCordintes = q.front();
            q.pop();
            int X = topCordintes.first.first;
            int Y = topCordintes.first.second;
            int minDist = topCordintes.second;

            for(int i=0;i<8;i++){
                int newX = X + dx[i];
                int newY = Y + dy[i];
                
                if(newX < grid.size() && newY < grid[0].size() && newX >= 0  && newY >= 0 &&
                    grid[newX][newY] == 0 && minDist+1 < dist[newX][newY] ){
                        dist[newX][newY] = minDist+1;
                        pair<int, int> newCordinates = make_pair(newX, newY);
                        q.push({newCordinates, minDist+1});

                    }
            }
        }

        if(dist[grid.size()-1][grid.size()-1] != INT_MAX) return dist[grid.size()-1][grid.size()-1]+1;
        return -1;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        
        if(grid[0][0] != 0) return -1;

        return solveUsingBFS(grid, dist);
    }
};