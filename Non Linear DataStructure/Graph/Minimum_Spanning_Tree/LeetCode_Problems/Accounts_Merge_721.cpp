#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


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
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> node_mail;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];

                if(node_mail.find(mail) == node_mail.end()){
                    node_mail[mail] = i;
                }
                else{
                    ds.unionBySize(i, node_mail[mail]);
                }
            }
        }

       unordered_map<int, vector<string>> merge_mail;
       for(auto &it: node_mail){
            string mail = it.first;
            int node = ds.findParent(it.second);

            merge_mail[node].push_back(mail);
       }

       vector<vector<string>> ans;

    
        for(auto &it: merge_mail){
            vector<string> output;
            if(it.second.size() == 0) continue;
            output.push_back(accounts[it.first][0]);

            sort(it.second.begin(), it.second.end());
            
            for(auto &it: it.second){
                output.push_back(it);
            }

            ans.push_back(output);
        }

        return ans;
    }
};

int main(){


    Solution s;
    vector<vector<string>> accounts = {{"John","johnsmith@mail.com","john_newyork@mail.com"},{"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}};

    vector<vector<string>> ans = s.accountsMerge(accounts);

    for(int i=0;i<accounts.size();i++){
        for(int j=0;j<accounts[i].size(); j++){
            cout<<accounts[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}