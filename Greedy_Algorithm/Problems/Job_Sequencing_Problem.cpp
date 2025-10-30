#include<bits/stdc++.h>
using namespace std;
class Job{
    public:
        int dead;
        int profit;
};
class Solution {
  public:
    static bool comp(Job a, Job b){
        return a.profit > b.profit;
    }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        
        vector<Job> arr;
        int n = profit.size();
        for(int i=0;i<n;i++){
           Job j;
           j.dead = deadline[i];
           j.profit = profit[i];
           arr.push_back(j);
        }
        
        sort(arr.begin(), arr.end(), comp);
        
        int maxi = arr[0].dead;
        for(int i=1;i<n;i++){
            maxi = max(maxi, arr[i].dead);
        }
        
        int total_profit = 0;
        int total_job = 0;
        // int id = 0;
        
        vector<int> ans(maxi+1, -1);
        
        for(int i=0;i<n;i++){
            
            for(int j=arr[i].dead;j>=1;j--){
                if(ans[j] == -1){
                    // id = id+1;
                    ans[j] = i;
                    total_profit += arr[i].profit;
                    total_job++;
                    break;
                }
            }
        }
        
        return {total_job, total_profit};
    }
};

int main(){
    Solution s;
    vector<int> deadline = {2, 1, 2, 1, 1};
    vector<int> profit ={100, 19, 27, 25, 15};
    vector<int> ans = s.jobSequencing(deadline, profit);

    cout<<"Total jobs: "<<ans[0]<<" Total Profit: "<<ans[1];

    return 0;
}






