class Solution {
private:
    void solveUsingBFS(int src, unordered_map<int, bool>& vis, vector<vector<int>>& isConnected){
        vis[src] = true;
        queue<int> q;
        q.push(src);

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for(int nbr=0; nbr<isConnected[frontNode].size(); nbr++){
                if(isConnected[frontNode][nbr] == 1 && !vis[nbr]){
                    vis[nbr] = true;
                    q.push(nbr);
                }
            }
        }
    }
    void solveUsingDFS(int src, unordered_map<int, bool>& vis, vector<vector<int>>& isConnected){
        vis[src] = true;

        for(int nbr = 0; nbr <isConnected[src].size(); nbr++){
            if(isConnected[src][nbr] == 1 && !vis[nbr]){
                solveUsingDFS(nbr, vis, isConnected);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, bool> vis;
        int n = isConnected.size();
        int provi = 0;
        // for(int i=0;i<n;i++){
        //     if(!vis[i]){
        //         solveUsingBFS(i, vis, isConnected);
        //         provi++;
        //     }
        // }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                solveUsingDFS(i, vis, isConnected);
                provi++;
            }
        }
 

        return provi;
    }
};