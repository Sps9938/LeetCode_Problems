#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>x;
        int  i,j,pre,next;
            for(i=0;i<nums.size();i++)
            {
                for(j=i;j<nums.size()-1;j++)
                {
                    if(nums[i]+nums[j+1]==target)
                    {
                        
                      return {i,j+1};
                    }
                }
            }
            return {};
    }
};
int main()
{
    Solution s1,s2,s3;
        int target;
        cin>>target;
        vector<int> v;
        for(int i=0;i<4;i++)
        {
            int d;
            cin>>d;
            v.push_back(d);
        }
        // Solution *p;
        // p=&s1;
        
        v=s1.twoSum(v,target);
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        

}