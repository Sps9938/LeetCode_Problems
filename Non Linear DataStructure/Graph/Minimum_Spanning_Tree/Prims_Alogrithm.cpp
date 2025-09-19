// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<unordered_map>
// #include<queue>
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int solveMinimumSpanningTreeUsingPrimsAlgo(unordered_map<int, vector<pair<int, int>>>& adjList, int V){
        unordered_map<int, bool> vis;
        
        priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
            > pq;
            
        pq.push({0, 0});
        int total_wt = 0;
        //first one is-> your node->wt and 2nd is your node
        
        while(!pq.empty()){
            auto topNode = pq.top();
            pq.pop();
            
            int node_wt = topNode.first;
            int node = topNode.second;
            
            if(vis[node]) continue;
            
            vis[node] = true;
            total_wt += node_wt;
            
            for(auto &it: adjList[node]){
                int nbr = it.first;
                int wt = it.second;
                
                if(!vis[nbr]){
                    pq.push({wt, nbr});
                }
            }
        }
        
        return total_wt;
    }
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, vector<pair<int, int>>> adjList;
        for(auto &it: edges){
            adjList[it[0]].push_back({it[1], it[2]});
            adjList[it[1]].push_back({it[0], it[2]});
        }
        
        return solveMinimumSpanningTreeUsingPrimsAlgo(adjList, V);
    }
};

int main(){
    Solution s;
    int V = 9; 

    // vector<vector<int>> edges = {{0, 1, 5},{1, 2, 3}, {0, 2, 1}};
    // vector<vector<int>> edges = { {0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> edges = { {1,5,4}, {1,4,1}, {1, 2, 2}, {2, 4, 3}, {2, 3, 3}, {3, 4, 5}, {2,6,7}, {3,6,8}, {4,5,9}};

    cout<<"MST IS: "<<s.spanningTree(V, edges);

    return 0;
}