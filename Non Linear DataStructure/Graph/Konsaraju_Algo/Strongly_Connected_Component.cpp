
#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;
//Position this line where user code will be pasted.
class Solution {
  private:
    void topoLogical_Order(vector<vector<int>>& adj, stack<int>& st, unordered_map<int, bool>& vis, int src){
        vis[src] = true;
        
        for(auto &nbr: adj[src]){
            if(!vis[nbr]){
                topoLogical_Order(adj, st, vis, nbr);
            }
        }
        
        st.push(src);
    }
    
private:
    void DFS(vector<vector<int>>& newAdj, unordered_map<int, bool>& vis, int src){
        vis[src] = true;
        
        for(auto &nbr: newAdj[src]){
            if(!vis[nbr]){
                DFS(newAdj, vis, nbr);
            }
        }
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        
        stack<int> st;
        unordered_map<int, bool> vis;
        int n = adj.size();
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                topoLogical_Order(adj, st, vis, i);
            }
        }
        //reverse
       
        vector<vector<int>> newAdj(n);
        
        for(int i=0;i<n;i++){
            for(auto nbr: adj[i]){
               newAdj[nbr].push_back(i);
            }
        }
        
        
        // find no provences
        unordered_map<int, bool> vis2;
        int scc =0;
        while(!st.empty()){
            int topNode = st.top();
            st.pop();
            
            if(!vis2[topNode]){
                DFS(newAdj, vis2, topNode);
                scc++;
            }
            
        }
        
        return scc;
        
    }
};

int main(){
    Solution s1;
    vector<vector<int>> adj = {{2, 3}, {0}, {1}, {4}, {}};

    cout<<"scc is: "<<s1.kosaraju(adj);

    return 0;
}