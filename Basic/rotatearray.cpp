#include <iostream>
using namespace std;
#include <vector>
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        vector<int> arr;
        int missans;
        int n = nums.size();
        for (int i = 0; i <= n; i++)
        {

            arr[i] = i;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (arr[i] != nums[j])
                {
                    count++;
                }
            }
            if (count == nums.size())
            {
                missans = arr[i];
                break;
            }
        }
        return missans;
    }
};
int main()
{
    vector<int> nums = {3,0,1};
    Solution s;
    int miss=s.missingNumber(nums);
    cout<<miss;

    return 0;
}