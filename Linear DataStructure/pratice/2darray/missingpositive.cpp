#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int rightelementinrightinde(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> arr(n, 0);
        int i = 0;
        while (i < n)
        {
            int t = nums[i];
            if (t < 0)
            {
                i++;
                if (i < n)
                    t = nums[i];
                else
                    break;
            }
            if (t - 1 >= 0 && t - 1 < n)
                arr[t - 1] = t;
            i++;
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] != i + 1)
                return i + 1;
        }
        if (i == n)
        {
            return i + 1;
        }
        return -1;
    }
    int brouteforcemethod(vector<int> &nums)
    {
        // int n=nums.size();
        // int i=1;
        // while(i)
        // {
        //     int j=0;
        //     while(j<n && i!=nums[j] )
        //         {
        //             j++;
        //         }
        //     if(j==n)
        //         return i;
        //     i++;
        // }
        // return i;
        int i = 1;
        int n = nums.size();
        int j = 0;
        while (j < n)
        {

            if (i == nums[j])
            {

                i++;
                j = 0;
            }
            else
            {
                j++;
            }
        }
        return i;
    }
    int firstMissingPositive(vector<int> &nums)
    {

        // return brouteforcemethod(nums);
        // return sortingmethod(nums);
        return rightelementinrightinde(nums);
    }
};
int main()
{
    Solution s;
    vector<int> nums{2, 3, 4, 5, 2, 6};
    cout << s.firstMissingPositive(nums);
    return 0;
}