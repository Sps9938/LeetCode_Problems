#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merge;
        vector<int> temp = intervals[0];

        for(auto &it: intervals){
            if(it[0] <= temp[1]){
                temp[1] = max(temp[1], it[1]);
            }
            else{
                merge.push_back(temp);
                temp = it;
            }
        }

        merge.push_back(temp);

        return merge;
    }
};

int main(){
    Solution s;
    vector<vector<int>> intervals = {{4,7},{1,4}};
    vector<vector<int>> ans = s.merge(intervals);



    return 0;
}