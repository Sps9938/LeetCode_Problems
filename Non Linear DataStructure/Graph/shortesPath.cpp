#include<iostream>
#include<queue>
#include<list>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Graph{

    public:
        unordered_map<int, list<pair<int, int>> > adjList;
    void insertEdge(int u, int v, int w, int dir){

        adjList[u].push_back({v, w});

        if(dir == 0){
            adjList[v].push_back({u, w});
        }

        // if(dir == 0){
        //     //undirected graph
        //     adjList[u].push_back({u, w});
        //     adjList[v].push_back({u, w});


        // }
        // else{
        //     //dir-> 1( it means directd graph)
        //     adjList[u].push_back({u, w});
        // }

    }
    void insertNode(int node){
       if(adjList.find(node) == adjList.end()){
        adjList[node] = {};
       }
    }

    void shortestPath(int src, unordered_map<int, bool>& vis, unordered_map<int, int>& parent){

        queue<int> q;
        
        vis[src] = true;
        // if(src != -2)
        parent[src] = -1;
        q.push(src);

        while(!q.empty()){
            int topElement = q.front();
            q.pop();

            for(auto nbr : adjList[topElement]){
                // cout<<"src: "<<topElement<<" nbr "<<nbr.first<<endl;

                if(!vis[nbr.first]){
                    // vis[true];
                    vis[nbr.first] = true;
                    q.push(nbr.first);
                    parent[nbr.first] = topElement;
                }
            }
        }

        // vector<int> ans;
        // int node = dest;
        // while(node != -1){
        //     ans.push_back(node);
        //     // cout<<node<<" ";

        //     node = parent[node];
        // }


        // cout<<"Print shortest Path: ";
        // // for(int i=0;i<ans.size();i++){
        // //         cout<<ans[i]<<" ";
        // // }

        // reverse(ans.begin(), ans.end());
        // for(auto i : ans){
        //     cout<<i<<" ";
        // }
        

    }

    void printAns(unordered_map<int, int>& parent){
        vector<int> shoretAns;
        for(int i=0;i<8;i++){
            int node = i;
            vector<int> ans;
            while(node != -1 && node != 0){
                ans.push_back(node);
                node = parent[node];
            }
            if(node == -1){
                shoretAns.push_back(-1);
            }
            else
                shoretAns.push_back(ans.size());

            
        }

        cout<<"print shortest path from src to  each node"<<endl;
        for(auto i : shoretAns){
            cout<<i<<" ";
        }
    }


};



int main(){


    Graph g;

    //ex-1
    // g.insertEdge(0, 1, 1, 0);
    // g.insertEdge(1, 0, 1, 0);
    // g.insertEdge(1, 3, 1, 0);
    // g.insertEdge(2, 1, 1, 0);
    // g.insertEdge(2, 3, 1, 0);
    // g.insertEdge(3, 1, 1, 0);
    // g.insertEdge(3, 2, 1, 0);
    // g.insertEdge(3, 4, 1, 0);
    // g.insertEdge(4, 3, 1, 0);
    // g.insertEdge(5, 4, 1, 0);

    //ex-2
    // g.insertEdge(0,1,1,0);
    // g.insertEdge(0,3,1,0);
    // g.insertEdge(1,0,1,0);
    // g.insertEdge(1,2,1,0);
    // g.insertEdge(2,1,1,0);
    // g.insertEdge(2,6,1,0);
    // g.insertEdge(3,0,1,0);
    // g.insertEdge(3,4,1,0);
    // g.insertEdge(4,3,1,0);
    // g.insertEdge(4,5,1,0);
    // g.insertEdge(5,4,1,0);
    // g.insertEdge(5,6,1,0);
    // g.insertEdge(6,2,1,0);
    // g.insertEdge(6,5,1,0);
    // g.insertEdge(6,7,1,0);
    // g.insertEdge(6,8,1,0);
    // g.insertEdge(7,6,1,0);
    // g.insertEdge(7,8,1,0);
    // g.insertEdge(8,7,1,0);
    // g.insertEdge(8,6,1,0);

    //ex-3
    // g.insertEdge(0,3,1,0);
    // g.insertEdge(1,3,1,0);
    // g.insertNode(2);
    // g.insertEdge(3,0,1,0);
    // g.insertEdge(3,1,1,0);

    //ex-4
    g.insertEdge(0,1,1,0);
    g.insertEdge(0,2,1,0);
    g.insertEdge(1,0,1,0);
    g.insertEdge(1,2,1,0);
    g.insertEdge(1,3,1,0);
    g.insertEdge(1,4,1,0);

    g.insertEdge(2,0,1,0);
    g.insertEdge(2,1,1,0);
    g.insertEdge(2,3,1,0);

    g.insertEdge(3,1,1,0);
    g.insertEdge(3,2,1,0);
    g.insertEdge(3,4,1,0);
  

    g.insertEdge(5,6,1,0);
    g.insertEdge(5,7,1,0);

    g.insertEdge(6,5,1,0);

    g.insertEdge(7,5,1,0);

    // g.insertEdge(0,1,1,0);

    unordered_map<int, bool> vis;
    unordered_map<int, int> parent;

   for(int i=0;i<8;i++){
    if(!vis[i]){
        g.shortestPath(i, vis, parent);
    }

   }
    g.printAns(parent);

    return 0;
}