#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int ans=0;
        int l = 0;
        int r = l + 1;
        while (l < r )
        {
            if (nums[l] != nums[r] && r != nums.size())
                r++;
            else if (r == nums.size())
            {
                l = l + 1;
                r = l + 1;
            }
            else
            {
                ans=nums[l];
                break;
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = {1, 3, 4, 2, 3};
    Solution s;
    int ans = s.findDuplicate(nums);
    cout << ans;
    return 0;
}