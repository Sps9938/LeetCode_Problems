class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
       priority_queue<pair<int,pair<int, int> >, vector<pair<int, pair<int, int>>>, greater<pair<int,pair<int, int>>> >pq;
       vector<vector<int>> dist(heights.size(), vector<int>(heights[0].size(), INT_MAX));

       dist[0][0] = 0;
       pq.push({0, {0, 0}});

       while(!pq.empty()){
            auto topElement = pq.top();
            pq.pop();
            int topElementDistance = topElement.first;
            int X = topElement.second.first;
            int Y = topElement.second.second;

            //if -> reach destination return 
            if(X == heights.size()-1 && Y == heights[0].size()-1){
                return dist[X][Y];
            }

            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};
            for(int i=0;i<4;i++){
                int newX = X + dx[i];
                int newY = Y + dy[i];

                if(newX < heights.size() && newX >= 0 && newY < heights[0].size() && newY >= 0){
                    int currentDistance = abs(heights[newX][newY] - heights[X][Y]);
                    int newMax = max(currentDistance, topElementDistance);

                    if(newMax < dist[newX][newY]){
                        dist[newX][newY] = newMax;
                        pq.push({newMax, {newX, newY}});
                    }
                }
            }
       }

       return 0;
    }
};