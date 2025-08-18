#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int j = 0, i = m; j < n; j++)
        {
            nums1[i] = nums2[j];
            i++;
        }
        for (int i = 0; i < m + n; i++)
        {
            for (int j = 0; j < m + n; j++)
            {
                if (nums1[j] > nums1[j + 1])
                    swap(nums1[j], nums1[j + 1]);
            }
        }
        // for (int i = 0; i < m + n; i++)
        // {
        //     cout << nums1[i] << " ";
        // }
       sort(nums1.begin(),nums1.end());
    }
};
int main()
{
    Solution s1;
    vector<int> v;
    vector<int> v1;
    int n, m;
    cin >> m;
    cin >> n;
    for (int i = 0; i < m; i++)
    {
        int d;
        cin >> d;
        v.push_back(d);
    }
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        v1.push_back(d);
    }
    s1.merge(v, v.size(), v1, v1.size());
    return 0;
}
