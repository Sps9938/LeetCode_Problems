#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findpivotindex(vector<int> &nums)
    {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        int mid = s + (e - s) / 2;
        if (s == e)
            return s;
        while (s < e)
        {
            if (mid + 1 < n && nums[mid] > nums[mid + 1])
                return mid;
            else if (mid - 1 >= 0 && nums[mid] < nums[mid - 1])
                return mid - 1;
            else if (nums[s] < nums[mid])
                s = mid + 1;
            else if (nums[s] > nums[mid])
                e = mid - 1;
            // jo hum hamesa bhulta hai
            mid = s + (e - s) / 2;
        }
        return 0;
    }
    int binarysearch(vector<int> &nums, int s, int e, int &target)
    {
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                s = mid + 1;
            else if (nums[mid] > target)
                e = mid - 1;
        }
        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int ans = -1;
        int pivot = findpivotindex(nums);
        if (target >= nums[0] && target <= nums[pivot])
            ans = binarysearch(nums, 0, pivot, target);
        else
            ans = binarysearch(nums, pivot + 1, n - 1, target);
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        v.push_back(data);
    }
    int target = 12;
    cout << endl;
    cout << "pivotindex is:" << s.search(v, target);
    return 0;
}