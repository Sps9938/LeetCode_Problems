#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<long long int> ans;
    const int MOD = 1000000007;
    long long int fibo(int n)
    {
        // if(n==0)
        //     return 0;
        // if(n==1)
        //     return 1;
        // return (fibo(n-1)+fibo(n-2)) % MOD;

        // using dynamic programming
        // base case
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (ans[n] != -1)
            return ans[n];
        ans[n] = (fibo(n - 1) + fibo(n - 2)) % MOD;
        return ans[n];
    }

    long long int topDown(int n)
    {

        // code here
        ans.resize(n + 1, -1);
        return fibo(n);
    }

    long long int bottomUp(int n)
    {
        // code here
        ans.resize(n + 1, -1);
        return fibo(n);
        // return sum;
    }
};
int main()
{
    Solution s;
    int n;
    cout << "Enter the value of n" << endl;
    cin >> n;
    cout << "For TopDown Approach the ans is" << endl;
    cout << s.topDown(n);
    cout << endl;
    cout << "For BottomUp Approach the ans is" << endl;
    cout << s.bottomUp(n);

    return 0;
}