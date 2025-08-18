#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findPairs(vector<int> &nums, int &k)
    {
        int i = 0, j;
        int n = nums.size();
        int count = 0;

        int ans = -1;
        int ans1=-1;
        while (i < n - 1)

        {
            j = i + 1;
            
            while (j < n)
            {

                int diff = nums[i] - nums[j];

                if (abs(diff) == k && nums[j] != ans)
                {
                    // cout<<nums[j]<<endl;
                    // int ans1=nums[i];
                    ans = nums[j];  // 1
                    // ans1 = nums[i]; // 3
                    count++;
                }

                j++;
            }
            i++;
        }
        return count;
    }
};
int main()
{
    Solution s;
    vector<int> v = {1,2,4,4,3,3,0,9,2};
    int target = 3;
    int ans = s.findPairs(v, target);
    if (ans == 0)
        cout << "No difference in an array" << endl;
    else
        cout << "Number of difference in an array is:" << ans;
    return 0;
}