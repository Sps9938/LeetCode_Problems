class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adjList;
        for(auto &it: roads){
            adjList[it[0]].push_back({it[1], it[2]});
            adjList[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        int MOD = 1000000007;

        //priority queue
        priority_queue<pair<long long, int>,
            vector<pair<long long, int>>, 
            greater<pair<long long, int>>
            > pq;
        pq.push({0, 0});

        dist[0] = 0;
        ways[0] = 1;

        while(!pq.empty()){
            auto topNode = pq.top();
            pq.pop();

           int node = topNode.second;
           long long total_dist = topNode.first;

            for(auto &it: adjList[node]){
                if(total_dist+it.second < dist[it.first]){
                    dist[it.first] = total_dist + it.second;
                    ways[it.first] = ways[node];
                    pq.push({total_dist+it.second, it.first});
                }
                else if(total_dist + it.second == dist[it.first]){
                    ways[it.first] = (ways[node] + ways[it.first]) % MOD;
                }
            }
        }

        return ways[n-1]%MOD;
    }
};