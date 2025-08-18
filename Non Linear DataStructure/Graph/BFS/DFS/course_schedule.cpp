class Solution {
private:
    void topSort(int n, unordered_map<int, list<int> >& adjList, vector<int>& ans){
        unordered_map<int, int> indegree;
        
        queue<int> q;

        for(auto task : adjList){
                int src = task.first;
                for(auto nbr : task.second){
                    indegree[nbr]++;
                }
        }

       for(int i=0;i<n;i++){
        if(indegree[i] == 0){  
            q.push(i);
        }

       }

       while(!q.empty()){
        int topElement = q.front();
        q.pop();
        // cout<<topElement<<" ";
        
        ans.push_back(topElement);
        for(auto nbr : adjList[topElement]){
            // cout<<"topElement"<<topElement<<" "<<"nbr"<<nbr<<endl;
            indegree[nbr]--;
            if(indegree[nbr] == 0){   
                q.push(nbr);
            }
        }

       }

       
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adjList;
        for(auto task : prerequisites){
            int u = task[1];
            int v = task[0];
            adjList[u].push_back(v);
        }
        vector<int> ans;
        topSort(numCourses, adjList, ans);
        if(ans.size() == numCourses) return ans;

        return {};
    }
};