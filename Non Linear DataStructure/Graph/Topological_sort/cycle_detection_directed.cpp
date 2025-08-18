class Solution {
    bool solveUsingBFS(int V, unordered_map<int, list<int>>& adjList){
        queue<int>q;
        unordered_map<int, int> indegree;
        int count = 0;
        
        for(auto list : adjList){
            for(auto nbr : list.second){
                indegree[nbr]++;
            }
        }
        
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            count++;
            
            for(auto nbr : adjList[frontNode]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
            
        }
    
        if(count == V) return false;
        return true;
        
        
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int, list<int>> adjList;
        for(auto list : edges){
            adjList[list[0]].push_back(list[1]);
        }
        
        
        return solveUsingBFS(V, adjList);
    }
};