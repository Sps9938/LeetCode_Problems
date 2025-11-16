#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        //left->segment 

        int i = 0;
        int n = intervals.size();
        while(i < n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i = i+1;
        }

        //may merge 
 
        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i = i+1;
        }

        ans.push_back(newInterval);

        while(i < n){
            ans.push_back(intervals[i]);
            i = i + 1;
        }

        return ans;

    }
};

int main(){

    Solution s;


    vector<vector<int>> intervals =  {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval = {4, 8};

    vector<vector<int>> ans = s.insert(intervals, newInterval);

    cout<<"The Intervals : "<<endl;
    cout<<"[";
   for(auto &it: ans){
    cout<<"["<<it[0]<<","<<it[1]<<"],";
   }
   cout<<"]";

    return 0;
}