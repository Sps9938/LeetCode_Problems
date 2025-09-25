#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;
class Solution {
private:
    int minimum_time_to_rise_the_water(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j){

        /*
            T.C = O(n^2 log(n)) | S.C = O(n^2)

        */
       priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>> 
        > pq;


        pq.push({grid[i][j], {i, j}});

        vis[i][j] = true;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        int min_time_max_cell = INT_MIN;

        while(!pq.empty()){
            auto topCordinates = pq.top();
            pq.pop();

            int min_time = topCordinates.first;
            min_time_max_cell = max(min_time_max_cell, min_time);
            int X = topCordinates.second.first;
            int Y = topCordinates.second.second;

            if(X == grid.size()-1 && Y == grid[0].size()-1) return min_time_max_cell;
        
            for(int i=0;i<4;i++){
                int newX = X + dx[i];
                int newY = Y + dy[i];
                if(newX < grid.size() && newY < grid[0].size() && newX >= 0 && newY >= 0 && !vis[newX][newY]){
                vis[newX][newY] = true;
                int curr_cell_time = grid[newX][newY];
                pq.push({curr_cell_time, {newX, newY}});
            }

            }

            
        }

        return -1;

    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), 0));

        int i=0;
        int j=0;
        return minimum_time_to_rise_the_water(grid, vis, i, j);

    }
};

int main(){

    Solution s1;
    vector<vector<int>> grid = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    cout<<"min time is: "<<s1.swimInWater(grid);
    return 0;
}