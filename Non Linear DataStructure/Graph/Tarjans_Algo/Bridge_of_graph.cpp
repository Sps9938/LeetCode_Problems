#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;
class Solution {
private:
    void solveUsingDFS(unordered_map<int, vector<int>>& adjList, int src, int timer, int parent, vector<int>& low, vector<int>& itr, unordered_map<int, bool>& vis, vector<vector<int>>& bridge){
        vis[src] = true;

        low[src] = timer;
        itr[src] = timer;
        timer++;

        for(auto &nbr: adjList[src]){
            if(nbr == parent) continue;

            if(!vis[nbr]){
                solveUsingDFS(adjList, nbr, timer, src, low, itr, vis, bridge);

                low[src] = min(low[src], low[nbr]);

                if(low[nbr] > itr[src]){
                    bridge.push_back({src, nbr});
                }
            }
            else{
                low[src] = min(low[src], low[nbr]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
         vector<int> low(n+1, 0);
         vector<int> itr(n+1, 0);

         unordered_map<int, vector<int>> adjList;

         for(auto &it: connections){
            adjList[it[0]].push_back({it[1]});
            adjList[it[1]].push_back({it[0]});
        }

        vector<vector<int>> bridge;

        int timer = 1;
        unordered_map<int, bool> vis;
        solveUsingDFS(adjList, 0, timer, -1, low, itr, vis, bridge);

        return bridge;
    }
};

int main(){
    Solution s1;

    vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3}};
        // vector<vector<int>> connections =  {{ 1, 3 }, { 1, 4 }, { 2, 1 }, { 3, 2 }, { 4, 5 }};
    int n = 4;

    cout<<"Bridge of Graph is: "<<endl;

    vector<vector<int>> bridge = s1.criticalConnections(n, connections);

    for(int i=0;i<bridge.size();i++){
        for(int j=0;j<bridge[i].size();j++){
            cout<<bridge[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}