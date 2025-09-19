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