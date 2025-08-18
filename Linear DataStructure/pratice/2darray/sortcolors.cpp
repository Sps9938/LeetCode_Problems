#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i;j<nums.size();j++)
            {
                if(nums[i]>nums[j+1])
                    swap(nums[i],nums[j+1]);
            }
        }
        
    }
};
int main()
{
    Solution s;
    vector<int>nums{2,0,2,1,1,0};
    s.sortColors(nums);
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
}