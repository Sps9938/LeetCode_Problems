class Solution {
private:
    void solveUsingFloydWarsharAlgoUsingDijKastra(unordered_map<int, vector<pair<int, int>>>& adjList, 
        vector<vector<int>>& dist, int n){

            /*
                T.C = O(n*(n+m)log(n)) = O(n^2(log(n))) | S.C = O(n^2+m)
                where n -> no of node
                     & m -> no of edges
            */
        priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
            > pq;
            for(int row=0;row<n; row++){
                dist[row][row] = 0;
                pq.push({0, row});

                while(!pq.empty()){
                    auto topNode = pq.top();
                    pq.pop();

                    int total_dist = topNode.first;
                    int node = topNode.second;

                    for(auto &it: adjList[node]){
                        if(total_dist + it.second < dist[row][it.first]){
                            dist[row][it.first] = total_dist+it.second;
                            pq.push({total_dist+it.second, it.first});
                        }
                    }
                }

            }
    }

private:
    void solveUsingHepler(vector<vector<int>>& edges, vector<vector<int>>& dist, int n){

           /*
                T.C = O(n^3) | S.C = O(n^2)
                where n -> no of node
    
            */

        for(int i=0;i<n;i++){
            dist[i][i] = 0;
        }

        for(auto &it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            dist[u][v] = min(dist[u][v], wt);
            dist[v][u] = min(dist[v][u], wt);
        }

        for(int helper=0; helper<n;helper++){
            for(int src=0; src<n; src++){
                for(int dst=0; dst<n; dst++){
                    if(dist[src][helper] + dist[helper][dst] < dist[src][dst]){
                        dist[src][dst] = dist[src][helper] + dist[helper][dst];
                    }
                }
            }
        }
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX/2));
        

        unordered_map<int, vector<pair<int, int>>> adjList;
        for(auto &it: edges){
            adjList[it[0]].push_back({it[1], it[2]});
            adjList[it[1]].push_back({it[0], it[2]});

        }
        solveUsingHepler(edges, dist, n);
        // solveUsingFloydWarsharAlgoUsingDijKastra(adjList, dist, n);
        
        unordered_map<int, int> countNoofPossible;
    
        for(int i=0;i<dist.size();i++){
            for(int j=0;j<dist[i].size();j++){
                if(i != j && dist[i][j] <= distanceThreshold){
                    countNoofPossible[i]++;
                }
            }
        }

        int min_path = INT_MAX;
        int ans = -1;
        for(int i=0;i<n;i++){
           if(countNoofPossible[i] <= min_path){
                min_path = countNoofPossible[i];
                ans = i;
           }
        }
 

        return ans;
        }

};