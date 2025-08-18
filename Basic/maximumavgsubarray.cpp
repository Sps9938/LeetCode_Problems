#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int maxsum = INT_MIN;

        // while (j < nums.size())
        // {
        //     j = i;
        //     count = 0;
        //     sum = 0;
        //     if (nums.size() > k)
        //     {
        //         while (count != k)
        //         {

        //             sum = sum + nums[j];

        //             j++;
        //             count++;
        //         }
        //     }
        //     else
        //     {
        //         sum = 0;

        //         while (i < nums.size())
        //         {
        //             sum = sum + nums[i];
        //             i++;

        //         }
        //         avg=sum/nums.size();
        //         break;
        //     }
        //             i++;
        //             // cout<<sum<<endl;
        //             // double maxavg = sum / k;
        //             // cout<<maxavg<<endl;
        //             if (maxavg > avg)
        //                 avg = maxavg;
        //         }

        //     return avg;
        // }
        int x = 0;
        int sum = 0;
        while (x < k)
        {
            sum = sum + nums[x];
            x++;
        }
        if (sum > maxsum)
            maxsum = sum;

        int i = 0;
        while (x < nums.size())
        {

            sum = sum - nums[i++];
            sum = sum + nums[x++];
            if (sum > maxsum)
                maxsum = sum;
        }
        double maxavg = maxsum / (double)k;
        return maxavg;
    }
};

int main()
{
    Solution s;
    double d;
    vector<int> nums = {-1};
    int k = 1;
    d = s.findMaxAverage(nums, k);
    cout << d;
    return 0;
}