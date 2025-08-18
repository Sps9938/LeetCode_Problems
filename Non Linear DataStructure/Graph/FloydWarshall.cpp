#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
class Solution {
  public:
  void solveUsingBFS(vector<vector<int>>& dist, vector<vector<int>>& edges){
      int row = edges.size();
    //   int col = edges[0].size();
      for(int src=0;src<row;src++){
        //   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
        // cout<<"src="<<src<<" ";
        set<pair<int, int>> st;
        //   pq.push({0, src});
        st.insert(make_pair(0, src));
          dist[src][src] = 0;
          
          while(!st.empty()){
            //   pair<int, int> topCordinates = pq.top();
            //   pq.pop();
            auto topCordinates = *(st.begin());
            st.erase(st.begin());
              
              int nodeDistance = topCordinates.first;
              int node = topCordinates.second;
              int col = 0;
            //   cout<<"node="<<node<<" ";
              for(auto nbr : edges[node]){
               
                
                // cout<<"nbr="<<nbr;
                // cout<<dist[src][node]<<" ";
                  if(nbr != 100000000 && nodeDistance + nbr < dist[src][col]){
                    // cout<<nodeDistance<<endl;
                      auto findResult = st.find(make_pair(dist[src][col], col));
                      if(findResult != st.end()){
                        //   pq.erase(findResult);
                        st.erase(findResult);
                      }
                      
                      dist[src][col] = nodeDistance + nbr;
                    //   cout<<"dist "<<dist[src][col]<<" nodedistance "<<nodeDistance<<" nbr "<<nbr<<endl;
                    //   cout<<dist[src][node]<<endl;
                    //   pq.push({make_pair(dist[src][nbr], nbr)});
                        st.insert(make_pair(dist[src][col], col));
                  }
                  col++;

                  
              }
              
              
          }
      }
  }
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        vector<vector<int>> ans(dist.size(), vector<int>(dist[0].size(), 100000000));
        
        solveUsingBFS(ans, dist);
        
        dist.clear();
        dist = ans;
        
    }


      void solveUsingHelper(vector<vector<int>>& dist){
    int n= dist.size();
    //   vector<vector<int>> ans(n, vector<int>(n, 100000000));
    //   for(int i=0;i<n;i++){
    //       ans[i][i] = 0;
    //   }
      
    //   for(int i=0;i<n;i++){
    //       for(int j=0;j<n;j++){
    //           ans[i][j] = dist[i][j];
    //       }
    //   }
    vector<vector<int>> ans(dist.begin(), dist.end());
      for(int helper = 0; helper<n; helper++){
          for(int src=0; src<n; src++){
              for(int dest = 0; dest<n; dest++){
                  // cout<<ans[src][helper] <<" " <<ans[helper][dest]<<endl;
                  if(ans[src][helper] != 100000000 && ans[helper][dest] != 100000000)
                    ans[src][dest] = min(ans[src][dest], ans[src][helper] + ans[helper][dest]);
              }
          }
      }
      
     dist.clear();
     dist  = ans;
     cout<<endl;
     cout<<"printeing dist"<<endl;
      
  }
};


int main(){

    Solution s;
    // vector<vector<int>> dist =  {{0, 4, 108, 5, 108}, {108, 0, 1, 108, 6}, {2, 108, 0, 3, 108}, {108, 108, 1, 0, 2}, {1, 108, 108, 4, 0}};
    vector<vector<int>> dist =  {{0, 100000000, -1, 9}, {9, 0, 5, 7}, {2, 100000000, 0, 8}, {-3, 100000000, 1, 0}};

    // s.floydWarshall(dist);
    s.solveUsingHelper(dist);
    cout<<endl;
    cout<<"printing dist of each node"<<endl;
    for(int i=0;i<dist.size();i++){
        for(int j=0;j<dist[0].size();j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}