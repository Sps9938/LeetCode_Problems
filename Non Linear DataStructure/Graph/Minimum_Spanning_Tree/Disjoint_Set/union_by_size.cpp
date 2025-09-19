#include<iostream>
using namespace std;
#include<vector>


/*
    T.C = O(n*A) | S.C = O(n)\
    where A is inverse Ackermann function

*/
class DisjoinSet{
    vector<int> parent, size;
public:
    DisjoinSet(int n){
        parent.resize(n+1, 0);
        size.resize(n+1, 1);

        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    //path->compression
    int findParent(int node){
        //base case 
        if(node == parent[node]) return node;

        return parent[node] = findParent(parent[node]);


    }

    void connect_with_node(int u, int v){
        int parent_u = findParent(u);
        int parent_v = findParent(v);
        
        if(parent_u == parent_v) return;

        if(size[parent[parent_u]] < size[parent_v]){
            parent[parent_u] = parent_v;
            size[parent_v] +=  size[parent_u];
        }
        else{
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
        
        
    }
};

int main(){

DisjoinSet ds(7);

ds.connect_with_node(1, 2);
ds.connect_with_node(2, 3);
ds.connect_with_node(4, 5);
ds.connect_with_node(6, 7);
ds.connect_with_node(5, 6);

if(ds.findParent(3) == ds.findParent(7)){
    cout<<"Same Parent"<<endl;
}
else{
    cout<<"Not Same Parent"<<endl;
}
ds.connect_with_node(3, 7);

cout<<"After node creation: "<<endl;
if(ds.findParent(3) == ds.findParent(7)){
    cout<<"Same Parent"<<endl;
}
    return 0;
}
