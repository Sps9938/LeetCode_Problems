#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>
#include<list>
#include<queue>
#include<algorithm>
class Solution {
private:
    void solveUsingBFS(unordered_map<int, list<int>>& adjListRevGraph, vector<int>& ans, int n){

        unordered_map<int, int> indegree;
        for(auto list : adjListRevGraph){
            for(auto nbr : list.second){
                indegree[nbr]++;
            }
        }

        //push into queue
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0) q.push(i);
        }


        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);
            for(auto nbr : adjListRevGraph[frontNode]){
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //step1: find each node outdegree-> reversse the graph and find each node inderee(which becomes the outdegree of actual graph)
        //step2: after reverse -> whose node indegree 0 insert into queue
        //step3: make sure in ans nodes coming only when indegree of node will be zero
        unordered_map<int, list<int>> adjListRevGraph;
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adjListRevGraph[graph[i][j]].push_back(i);
            }
        }

        vector<int> ans;
        int size = graph.size();
        solveUsingBFS(adjListRevGraph, ans, size);
        if(ans.size()) sort(ans.begin(), ans.end()); 
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> ans = s.eventualSafeNodes(graph);
    cout<<"safe nodes are: ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}