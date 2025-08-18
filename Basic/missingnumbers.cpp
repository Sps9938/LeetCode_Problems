#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    public:
    int missingnumber(vector<int> &nums)
    {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
        }
        int totalsum=(n*(n+1))/2;
        int ans=totalsum-sum;
        return ans;  
    }
      
};
int main()
{
    vector<int>nums={3,1,0,2};
    Solution s;

   int ans= s.missingnumber(nums);
   cout<<ans;
   return 0;
}