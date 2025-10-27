#include<bits/stdc++.h>
using namespace std;

class Item{
    public:
        int value;
        int weight;
};
class Solution {
  public:
    bool static comp(Item a, Item b){
        double r1 = (double)a.value/(double)a.weight;
        double r2 = (double)b.value/(double)b.weight;
        
        return r1>r2;
        
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<Item> arr(n);
        for(int i=0;i<n;i++){
            arr[i].value = val[i];
            arr[i].weight = wt[i];
        }
        sort(arr.begin(), arr.end(), comp);
        
        int curr_wt = 0;
        double final_val = 0.0;
        for(int i=0;i<n;i++){
            if(curr_wt + arr[i].weight <= capacity){
                curr_wt += arr[i].weight;
                final_val += arr[i].value;
            }
            else{
                int remain_wt = capacity - curr_wt;
                final_val += (arr[i].value/(double)arr[i].weight)* (double)remain_wt; 
                break;
            }
        }
        
        return final_val;
    }
};

int main(){
    Solution s;
    vector<int> val = {60, 100, 180};
    vector<int> wt = {15, 20, 3};
    int capacity = 20;
    cout<<"maximizd val is: "<<s.fractionalKnapsack(val, wt, capacity);

    return 0;
}