#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, maxLen = 0;
        int zero = 0;
        int n = nums.size();
        while(r < n){
            if(nums[r] == 0) zero++;
            if(zero > k){
                if(nums[l] == 0) zero--;
                l++;
            }
            if(zero <= k){
                int len = r - l + 1;
                maxLen = max(len, maxLen);
            }
            r++;
        }

        return maxLen;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout<<"longest ones is: "<<s.longestOnes(nums, k);
    return 0;
}