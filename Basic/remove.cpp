#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
     {
        int i, j = 1;
        for (i = 1; i < nums.size(); i++) 
        {
            if (nums[i] != nums[i - 1])
            {
                nums[j]=nums[i];
                j++;
            }
        }
       
        return j;
    }
};
int main()
{
    Solution s;
    int p;
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        nums.push_back(d);
    }
    p = s.removeDuplicates(nums);
    cout << p;
}