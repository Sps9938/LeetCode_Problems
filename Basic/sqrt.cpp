#include <iostream>
using namespace std;
class Solution
{
public:
    int mySqrt(int x)
    {
        // for(int i=1;i<=x;i++)
        // {
        // int d=x/i;
        // if(d*d<=x)
        //     return d;
        //}
        int s = 1;
        int e = x - 1;
        int ans = 0;
        int mid = s + (e - s) / 2;
        while (s <= e)
        {
            if (mid * mid == x)
                return mid;
            else if (mid * mid < x)
            {
                ans = mid;
                s = mid + 1;
            }
            else if (mid * mid > x)
                e = mid - 1;
            mid = s + (e - s) / 2;
        }

        return ans;
    }
};
int main()
{
    Solution s;
    int n;
    cin >> n;
    cout << s.mySqrt(n);
    return 0;
}