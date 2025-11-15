#include<bits/stdc++.h>
using namespace std;

int solveSJF(vector<int> &arr){
    sort(arr.begin(), arr.end());
    int n = arr.size();

    int wt_time = 0;
    int total_time = 0;

    for(int i=0;i<n;i++){
        wt_time += total_time;
        total_time += arr[i];
    }

    return wt_time/n;
    
}
int main(){

    vector<int> arr = {4, 1, 3, 7, 2};
    int wt = solveSJF(arr);
    cout<<"Average of waiting time is: "<<wt;
    return 0;
}