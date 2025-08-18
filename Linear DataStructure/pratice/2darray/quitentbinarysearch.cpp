#include <iostream>
using namespace std;
class Solution
{
public:
    int qutient(int &N, int &x)
    {
        int s = 1;
        int e = N;
        int ans = 0;
        long long int mid = s + (e - s) / 2;
        while (s <= e)
        {
            if (mid * x == N)
                return mid;
            else if (mid * x < N)
            {
                ans = mid;
                s = mid + 1;
            }
            else if (mid * x > N)
                e = mid - 1;
            mid = s + (e - s) / 2;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    int N, x;
    cin >> N >> x;
    cout << "Result is:" << s.qutient(N, x);
    return 0;
}