
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
#include<set>
class DisjointSet{
    public:
        vector<int> rank, size, parent;

    DisjointSet(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);

        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }


    int findParent(int node){
        if(parent[node] == node) return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] == rank[ulp_v]){
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;

        }
        else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else{
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

    /*
        T.C = O(n^2) | S.C = O(n^2)

    */
private:
    bool isValid(int n, int newX, int newY){
        return newX < n && newY < n && newX >= 0 && newY >= 0;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        
        DisjointSet ds(n*n);

        for(int X=0; X<n;X++){
            for(int Y=0;Y<n;Y++){
                if(grid[X][Y] == 0) continue;
                int dx[] = {-1, 0, 1, 0};
                int dy[] = {0, -1, 0, 1};
                for(int i=0;i<4;i++){
                    int newX = X + dx[i];
                    int newY = Y + dy[i];
                    if(isValid(grid.size(), newX, newY) && grid[newX][newY] == 1){
                        int src_node = X * n + Y;
                        int adj_node = newX * n + newY;
                        if(ds.findParent(src_node) != ds.findParent(adj_node)){
                            ds.unionBySize(src_node, adj_node);
                        }         
                    }
                }
            }
        }



        int mx = 0;
      
            for(int X=0; X<n;X++){
            for(int Y=0;Y<n;Y++){
                if(grid[X][Y] == 1) continue;
                int dx[] = {-1, 0, 1, 0};
                int dy[] = {0, -1, 0, 1};
                set<int> components;
               
                for(int i=0;i<4;i++){
                    int newX = X + dx[i];
                    int newY = Y + dy[i];
                    
                    if(isValid(grid.size(), newX, newY) && grid[newX][newY] == 1){
                        components.insert(ds.findParent(newX * n + newY));
                    }
                }
                int size_total = 0;
                for(auto &it: components){
                    size_total += ds.size[it]; 
                }
                mx = max(mx, size_total+1);
            }
        }

        for(int i=0;i<n*n;i++){
            mx = max(mx, ds.size[ds.findParent(i)]);
        }

        return mx;
    }
};

int main(){

    Solution s1;

    vector<vector<int>> grid =  {{1,0},{0,1}};

    cout<<"large Island Area is: "<<s1.largestIsland(grid);

    
    return 0;
}