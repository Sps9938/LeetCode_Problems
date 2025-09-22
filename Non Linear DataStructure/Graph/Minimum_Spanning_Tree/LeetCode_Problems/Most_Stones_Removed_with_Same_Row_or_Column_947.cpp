#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class DisjointSet{
    public:
        vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    
    
    int findParent(int node){
        
      if(node == parent[node]) return node;
      
      return parent[node] = findParent(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        
        if(ulp_u == ulp_v) return;
        
        if(rank[ulp_u] == rank[ulp_v]){
            parent[ulp_v] = ulp_u;
            rank[u] += 1;
        }
        else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
    }
    void unionBySize(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        
        if(ulp_u == ulp_v) return;
        
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int maxRow = 0;
        int maxCol = 0;
        unordered_map<int, int> unique_stone;
        for(auto &it: stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        int n = maxRow + maxCol + 1;

        DisjointSet ds(n);
        
        for(auto &it: stones){
            int nodeRow = it[0];
            int nodeCol = maxRow + it[1] + 1;

            if(ds.findParent(nodeRow) != ds.findParent(nodeCol)){
                ds.unionBySize(nodeRow, nodeCol);
                unique_stone[nodeRow] = 1;
                unique_stone[nodeCol] = 1;
            }



        }

        int cp = 0;
        for(auto &it: unique_stone){
            // cout<<"stones: "<<it.first<<" ";
            if(ds.findParent(it.first) == it.first){
                cp++;
            }
        }
        // cout<<endl;
        // cout<<"no of component: "<<cp<<endl;
        int noOf_Stone = stones.size();
        int min_stone_remove = noOf_Stone - cp;
        return min_stone_remove;
        
    }
};

int main(){
    Solution s;

    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};

    cout<<"Longest Possible Stones removed is: "<<s.removeStones(stones);
    return 0;
}