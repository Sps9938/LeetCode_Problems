#include <iostream>
#include <vector>
#include <deque>
using namespace std;
class Deque
{
public:
    deque<int> maxq;
    deque<int> minq;
    int ans = 0;
    int maxAndminElementofSubarrayusingWindow(int nums[], int k, int size)
    {
        for (int i = 0; i < k; i++)
        {
            // To find maxelement
            while (!maxq.empty() && nums[i] >= nums[maxq.back()])
            {
                maxq.pop_back();
            }
            maxq.push_back(i);

            // To find minelement
            while (!minq.empty() && nums[i] <= nums[minq.back()])
            {
                minq.pop_back();
            }
            minq.push_back(i);
        }
        int maxValue = nums[maxq.front()];
        int minValue = nums[minq.front()];
        ans += maxValue + minValue;

        // now find min and max element ,remaning element
        for (int i = k; i < size; i++)
        {
            // check current element is in window or not
            if (!maxq.empty() && i - maxq.front() >= k)
            {
                maxq.pop_front();
            }
            while (!maxq.empty() && nums[i] >= nums[maxq.back()])
            {
                maxq.pop_back();
            }
            maxq.push_back(i);

            // for min element
            // check current element is in window or not
            if (!minq.empty() && i - minq.front() >= k)
            {
                minq.pop_front();
            }
            while (!minq.empty() && nums[i] <= nums[minq.back()])
            {
                minq.pop_back();
            }
            minq.push_back(i);

            maxValue = nums[maxq.front()];
            minValue = nums[minq.front()];
            ans += maxValue + minValue;
        }
        return ans;
    }
};

int main()
{
    Deque dq;
    int nums[] = {2, 5, -1, 7, -3, -1, -2};
    int size = sizeof(nums) / sizeof(int);
    cout << dq.maxAndminElementofSubarrayusingWindow(nums, 3, size);

    return 0;
}