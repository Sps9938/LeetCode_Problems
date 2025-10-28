#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_index = 0;
        for(int i=0;i<nums.size()-1;i++){
            // if(nums[i] != 0)
            //     max_index = max(max_index, nums[i]+i);
            // else if(nums[i] == 0 && max_index <= i) return false;

            if(i<=max_index){
                max_index = max(max_index, nums[i]+i);
            }
            else return false;

            // cout<<"max_index: "<<max_index<<endl;
        }

        if(max_index >= nums.size()-1) return true;
        return false;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,2,1,0,4};
    cout<<"can possible to jump: "<<s.canJump(nums);
    return 0;
}