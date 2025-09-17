class Solution {
private:
    int solveUsingDijKastraAlgo(unordered_map<int, vector<pair<int, int>>>& adjList, vector<int>& dist, int k){
        priority_queue<pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
        > pq;

        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()){
            auto topNode = pq.top();
            pq.pop();
            int node = topNode.second;
            int total_time = topNode.first;

            for(auto &it: adjList[node]){
                if(total_time + it.second < dist[it.first]){
                    dist[it.first] = total_time + it.second;
                    pq.push({total_time + it.second, it.first});
                }
            }


        }

        int min_time = 0;
        for(int i=1;i<dist.size();i++){
            if(dist[i] == INT_MAX) return -1;
            min_time = max(min_time, dist[i]);
        }
        return min_time;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adjList;
        for(auto &it: times){
            adjList[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n+1, INT_MAX);

        return solveUsingDijKastraAlgo(adjList, dist, k);

    }
};