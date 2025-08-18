#include<iostream>
#include<unordered_set>
#include<set>
using namespace std;
int main(){
    int arr[] = {100, 3, 200, 4, 1, 2};
    unordered_set<int> st;
    set<int> s;
    for(int i=0;i<6;i++){
        // st.insert(arr[i]);
        s.insert(arr[i]);
    }
   for(auto n:s){
    cout<<n<<" ";
   }

    return 0;
}