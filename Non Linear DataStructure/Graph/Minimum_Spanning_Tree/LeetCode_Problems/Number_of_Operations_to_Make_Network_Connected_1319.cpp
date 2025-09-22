#include<iostream>
#include<vector>
using namespace std;


class DisjointSet{
    public:
        vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    //path compression
    int findParent(int node){
        if(node == parent[node]) return node;

        return parent[node] = findParent(parent[node]);
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdges = 0;
        for(auto &it: connections){
            int u = it[0];
            int v = it[1];
      

            if(ds.findParent(u) == ds.findParent(v)){
                extraEdges++;
            }
            else{
                ds.unionBySize(u, v);
            }
        }

        int nc = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i] == i){
                nc++;
            }
        }

        int ans = nc-1;

        return extraEdges >= ans ? ans : -1;
    }
};

int main(){

    Solution s;
    vector<vector<int>> connnections = {{0,1}, {0,2}, {0,3}, {1, 2}, {2, 3}, {4, 5}, {5, 6}, {7, 8}};

    int n = 9;

    cout<<"Minimum operation is: "<<s.makeConnected(n, connnections);

    return 0;
}