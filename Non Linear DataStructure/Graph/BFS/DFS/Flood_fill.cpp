class Solution {
private:
    void solveUsingBFSRevision(vector<vector<int>>& ansImage, int sr, int sc, int color){
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int oldColor = ansImage[sr][sc];
        ansImage[sr][sc] = color;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        while(!q.empty()){
            pair<int, int> frontCordinates = q.front();
            q.pop();
            int X = frontCordinates.first;
            int Y = frontCordinates.second;

            for(int i=0;i<4;i++){
                int newX = X + dx[i];
                int newY = Y + dy[i];

                if(newX < ansImage.size() && newY < ansImage[0].size() && newX >=0 && newY >= 0 &&
                ansImage[newX][newY] == oldColor && ansImage[newX][newY] != color){
                    ansImage[newX][newY] = color;
                    q.push({newX, newY});
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ansImage = image;
        solveUsingBFSRevision(ansImage, sr, sc, color);

        return ansImage;
    }
};