#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<list>
using namespace std;
template<typename T> 
class Graph{

    public:
        unordered_map<T, list<pair<T, int>> > adjList;
        // void print(){
        //     for(auto src : adjList){
        //         cout<<src.first<<"->"<<"{";
        //         for(auto nbr : src.second){
        //             cout<<nbr<<",";
        //         }
        //         cout<<"}";
        //         cout<<endl;
        //     }5
        //     cout<<endl;
        // }
        // void AddEdge(int u, int v, bool direction){
        //     //direction->0 -> undircted
        //     //direction->1 -> directed
        //     if(direction == 1){
        //         //for->directed
        //         //u->v
        //         adjList[u].push_back(v);
        //     }
        //     else{
        //         //for -> undirected
        //         //u->v and v->u
        //         adjList[u].push_back(v);
        //         adjList[v].push_back(u);
        //     }

        //     print();
        // }

        void print(){
            for(auto src : adjList){
                cout<<src.first<<"->"<<"{ ";
                for(auto pair : src.second){
                    cout<<"{"<<pair.first<<","<<pair.second<<"}"<<", ";
                }
                cout<<" }"<<endl;
            }
            cout<<endl;
        }

        void AddEdgeWighWeight(int u, int v, int weight, bool direction){
            if(direction == 1){
                adjList[u].push_back({v, weight});
        
            }
            else{
                adjList[u].push_back({v,weight});
                adjList[v].push_back({u, weight});
            }

            print();

    }

    void BFS(T src,  unordered_map<char, bool>& vis){
        
        vis[src] = true;

        queue<T> q;
        q.push(src);

        while(!q.empty()){
            T front = q.front();
            cout<<front<<" ";
            q.pop();
            
            for(auto nbr : adjList[front]){
                
                T nbrData = nbr.first;
                if(!vis[nbrData]){
                    q.push(nbrData);
                    vis[nbrData] = true;
                }
            }

        }


    }

    void DFS(T src, unordered_map<T, bool>& vis){
        
        vis[src] = true;
        cout<<src<<" ";

        for(auto nbr : adjList[src]){
            T nbrData = nbr.first;
            if(!vis[nbrData]){
                DFS(nbrData, vis);
            }
        }
    }
};
int main(){

    Graph <char> g;
    // g.AddEdge(1, 2, 0);
    // g.AddEdge(2, 3, 0);
    // g.AddEdge(3, 4, 0);
    // g.AddEdge(4, 5, 0);
    g.AddEdgeWighWeight('a', 'b', 5, 1);
    g.AddEdgeWighWeight('b', 'c', 10, 1);
    g.AddEdgeWighWeight('d', 'e', 15, 1);
    g.AddEdgeWighWeight('e', 'f', 20, 1);
    g.AddEdgeWighWeight('f', 'g', 20, 1);
    
    cout<<endl;
    // cout<<"BFS is: ";

    // unordered_map<char, bool> vis;
    // for(char node = 'a'; node<='f';node++){
    //    if(!vis[node]){
    //      g.BFS(node, vis);
    //    }
    // }
    // g.BFS('a');
    cout<<"DFS is: ";
    unordered_map<char, bool> vis;
     for(char node = 'a'; node<='g';node++){
       if(!vis[node]){
         g.DFS(node, vis);
       }
    }

    // g.DFS('a', vis);
  
    
    return 0;
}