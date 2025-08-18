#include <iostream>
#include <vector>
using namespace std;
// // class Solution
// {
//     public :
//         int pivotIndex(vector<int> & nums){
//             /* int ans = -1;
//              int n = nums.size();
//              int left, right;
//              int ls, rs;
//              for (int pivot = 0; pivot < n; pivot++)
//              {
//                  ls = 0, rs = 0;
//                  if (pivot != 0 && pivot != n - 1)
//                  {
//                      left = pivot - 1, right = pivot + 1;
//                      while (left >= 0)
//                      {
//                          ls = ls + nums[left];
//                          left--;
//                      }
//                      while (right <= n - 1)
//                      {
//                          rs = rs + nums[right];
//                          right++;
//                      }
//                  }
//                  else
//                  {
//                      if (pivot == 0)
//                      {
//                          right = pivot + 1;
//                          while (right <= n - 1)
//                          {
//                              rs = rs + nums[right];
//                              right++;
//                          }
//                      }
//                      else if (pivot == n - 1)
//                      {
//                          left = pivot - 1;
//                          while (left >= 0)
//                          {
//                              ls = ls + nums[left];
//                              left--;
//                          }
//                      }
//                  }
//                  if (ls == rs)
//                  {
//                      ans = pivot;
//                      break;
//                  }
//              }
//              return ans;*/
//             // using for loop and optimized the above code
//             for (int i = 0; i < nums.size(); i++){
//                 int ls = 0;
// int rs = 0;
// for (int j = 0; j < i; j++)
// {
//     ls += nums[j];
// }
// for (int j = i + 1; j < nums.size(); j++)
// {
//     rs += nums[j];
// }
// if (ls == rs)
//     return i;
// }
// return -1;
// }
// }
class Solution
{
public:
    int newtwoarraylsrs(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ls(n, 0);
        vector<int> rs(n, 0);
        int i, j;
        // store for leftsum of current pivot
        for (j = 1; j < n; j++)
        {

            ls[j] = ls[j - 1] + nums[j - 1];
        }
        // store for rightsum of current pivot
        for (j = n - 2; j >= 0; j--)
        {

            rs[j] = rs[j + 1] + nums[j + 1];
        }
        for (i = 0; i < n; i++)
        {
            cout << "for" << " " << i << " index " << "left sum=" << ls[i] << endl;
            cout << "for" << " " << i << " index " << "right sum=" << rs[i] << endl;

            if (ls[i] == rs[i])
                return i;
        }
        return -1;
    }
    int pivotIndex(vector<int> &nums)
    {
        return newtwoarraylsrs(nums);
    }
};
int main()
{
    vector<int> nums = {3, -3, 2};
    Solution s;
    int an = s.pivotIndex(nums);
    cout << an;
    return 0;
}