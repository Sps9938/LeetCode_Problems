class Solution {
private:
    int sovleUsingBFSRevision(vector<vector<int>>& oranges){
        queue<pair<pair<int, int>, int>> rotten;
        int minTime = 0;
        int freshOranges = 0;
        for(int i=0;i<oranges.size();i++){
            for(int j=0;j<oranges[i].size();j++){
                if(oranges[i][j] == 2){
                    pair<int, int> cordinates = make_pair(i, j);
                    rotten.push({cordinates, 0});
                }
                else if(oranges[i][j] == 1){
                    freshOranges++;
                }
            }
        }
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!rotten.empty()){
            auto frontRotten = rotten.front();
            rotten.pop();
            int X = frontRotten.first.first;
            int Y = frontRotten.first.second;
            int totalTime = frontRotten.second;

            for(int i=0;i<4;i++){
                int newX = X + dx[i];
                int newY = Y + dy[i];

                if(newX < oranges.size() && newY < oranges[0].size() && newX >= 0 && newY >= 0 &&
                oranges[newX][newY] == 1){
                    oranges[newX][newY] = 2;
                    pair<int, int> cordinates = make_pair(newX, newY);
                    minTime = max(minTime, totalTime+1);
                    rotten.push({cordinates, totalTime+1});
                    freshOranges--;
                }
            }

        }
        return freshOranges ? -1 : minTime;

    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> oranges = grid;
        return sovleUsingBFSRevision(oranges);


    }
};