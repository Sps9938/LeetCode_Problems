//using BFS
class Solution {
    
private:
    void solveUsingBFS(int V,  unordered_map<int, list<int>>& adjList, vector<int>& ans){
        queue<int> q;
       
        //mark indegree
        unordered_map<int, int> indegree;

        
        for(auto list : adjList){
            for(auto nbr : list.second){
                indegree[nbr]++;
            }
        }
        
        
        //push int queue whose indegree is zero
      
        for(int i=0;i<V;i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);
            
            for(auto nbr : adjList[frontNode]){
                    indegree[nbr]--;
                    if(indegree[nbr] == 0) {
                        q.push(nbr);
                    }
            }
        }
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        //step 1 : count indegree of all source
        //step2 which src -> indegree is zero push int queue
        //step 3 till all src inderee not zero 
        
        
        unordered_map<int, list<int>> adjList;
        
        for(auto list : edges){
            adjList[list[0]].push_back(list[1]);
        }
        vector<int> ans;

        solveUsingBFS(V, adjList, ans);
     
        
        return ans;
        
        
        
    }
};







//using DFS
class Solution {
private:
    void solveUsingDFS(int src, unordered_map<int, list<int>>& adjList, stack<int>& st,  unordered_map<int, bool>& vis){
        vis[src] = true;
        for(auto nbr : adjList[src]){
            if(!vis[nbr]){
                solveUsingDFS(nbr, adjList, st, vis);
            }
        }
        st.push(src);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, list<int>> adjList;
        for(auto list : edges){
            adjList[list[0]].push_back(list[1]);
        }
        
        unordered_map<int, bool> vis;
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                solveUsingDFS(i, adjList, st, vis);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        // cout<<"ans size:"<<ans.size()<<endl;
        return ans;
    }
};

