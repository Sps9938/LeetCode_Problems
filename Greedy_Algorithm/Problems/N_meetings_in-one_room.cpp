#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<tuple<int, int, int>> meetings;
        int n= start.size();
        for(int i=0;i<n;i++){
            meetings.push_back({end[i], start[i], i+1});
        }
        
        
        sort(meetings.begin(), meetings.end());
        
        int lastend = -1;
        
        vector<int> ans;
        
        for(auto &it: meetings){
            int e = get<0> (it);
            int s = get<1> (it);
            int t = get<2> (it);
            
            if(s > lastend){
                ans.push_back(t);
                lastend = e;
            }
            
        }
        
        return ans.size();
    }
};

int main(){

    Solution s;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 5, 7, 9, 9};

    cout<<"Possible meetings: "<<s.maxMeetings(start, end);
    return 0;
}