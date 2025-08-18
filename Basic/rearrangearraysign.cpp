//rearrange array ,alternate postive and negative
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> v;
        vector<int> r;
        // int j=0,k=0;
        // here no need to intialise j and k value we used push_back(data) operation

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                // v[j]=nums[i];
                // j++;
                //here rutime error found -> no need to this copy method used in arry only
                //push_back(data) must be used in vector if copy anoter vector

                v.push_back(nums[i]);
            }
            else if (nums[i] < 0)
            {
               r.push_back(nums[i]);
            }
        }
        int l = 0;
        int m = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 0)
            {
                nums[i] = v[l];
                l++;
            }
            else if (i % 2 != 0)
            {
                nums[i] = r[m];
                m++;
            }
        }
        return nums;
    }
};
int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> v;
    Solution s;
    v = s.rearrangeArray(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}