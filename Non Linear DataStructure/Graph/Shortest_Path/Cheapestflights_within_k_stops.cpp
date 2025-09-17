class Solution {
private:
    int solveUsingDijKatraAlgo(unordered_map<int, vector<pair<int, int>>>& adjList, int src, int dst, int k, vector<vector<int>>& dist){
       priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int,int>>> 
        > pq;

        dist[src][0] = 0;
        pair<int, int> topSrc = make_pair(src, -1);
        pq.push({0, topSrc});
        int min_Dist = INT_MAX;

        while(!pq.empty()){
            auto topNode = pq.top();
            pq.pop();

            int total_Dist = topNode.first;
            int flight = topNode.second.first;
            int remain_Routes = topNode.second.second;
            cout<<"Flights: "<<flight<<endl;
            if(flight == dst) {
                min_Dist = min(min_Dist, total_Dist);
            }
            if(remain_Routes >= k) continue;

            for(auto &it: adjList[flight]){
                if(total_Dist + it.second < dist[it.first][remain_Routes+1]){
                    dist[it.first][remain_Routes+1] = total_Dist + it.second;
                    pair<int, int> newSrc = make_pair(it.first, remain_Routes+1);
                    pq.push({total_Dist + it.second, newSrc});
                }
            }
        }
        cout<<"min_Dist"<<min_Dist<<endl;
        return min_Dist == INT_MAX ? -1 : min_Dist;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adjList;
        for(auto &it: flights){
            adjList[it[0]].push_back({it[1], it[2]});
        }
        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        return solveUsingDijKatraAlgo(adjList, src, dst, k, dist);
    }
};