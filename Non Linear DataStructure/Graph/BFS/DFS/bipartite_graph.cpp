class Solution {
private:
    bool solveUsingDFS(unordered_map<int, list<int>>& adjList, vector<char>& setGroup, int node, char group){
        setGroup[node] = group;

        for(auto nbr : adjList[node]){
            if(setGroup[nbr] == '\0'){
                if(group == 'A') {
                    bool ans = solveUsingDFS(adjList, setGroup, nbr, 'B');
                    if(!ans) return false;
                }
                else {
                    bool ans = solveUsingDFS(adjList, setGroup, nbr, 'A');
                    if(!ans) return false;
                }
                
            }
            else if(setGroup[nbr] == group) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<char> setGroup(graph.size(), '\0');
        unordered_map<int, list<int>> adjList;
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adjList[i].push_back(graph[i][j]);
            }
        }

        for(int i=0;i<graph.size();i++){
            if(setGroup[i] == '\0'){
                if(!solveUsingDFS(adjList, setGroup, i, 'A')) return false;
            }
        }

        return true;
    }
};