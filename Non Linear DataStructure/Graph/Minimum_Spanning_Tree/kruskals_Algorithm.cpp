#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class DisjointSet{
    vector<int> size, parent;
public:
    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        
    }
    
    int findParent(int node){
        if(node == parent[node]) return node;
        
        return parent[node] = findParent(parent[node]);
    } 
    
    void connect_with_node_by_size(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        
        if(ulp_u == ulp_v) return;
        
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += ulp_v;
        }
    }
    
    
};
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<pair<int, pair<int, int>>> adjList;
        for(auto &it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adjList.push_back({wt, {u, v}});
        }
        
       sort(adjList.begin(), adjList.end());
       int mstWt = 0;
       
       DisjointSet ds(V);
       
       for(auto &it: adjList){
           int wt = it.first;
           int u = it.second.first;
           int v = it.second.second;
           
           if(ds.findParent(u) != ds.findParent(v)){
               mstWt += wt;
               ds.connect_with_node_by_size(u, v);
           }
       }
       
       return mstWt;
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