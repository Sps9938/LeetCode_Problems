#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
// vector<bool> primeOptimized(int n)
// {
//     vector<bool> prime(n + 1, true);
//     prime[0] = prime[1] = false;
//     for (int i = 2; i * i <= n; i++)
//     {
//         int j = i * i;
//         while (j <= n)
//         {
//             prime[j] = false;
//             j += i;
//         }
//     }
//     return prime;
// }
// vector<bool> primelowerandhigher(int l, int r)
// {
//     vector<bool> seive = primeOptimized(sqrt(r));
//     vector<int> baseprime;
//     for (int i = 0; i < seive.size(); i++)
//     {
//         if (seive[i])
//             baseprime.push_back(i);
//     }
//     vector<bool> ansprime(r - l + 1, true);
//     // if (l == 1 || l == 0)
//     // {
//     //     ansprime[l] = false;
//     // }
//     if(l==1)
//     {
//         ansprime[0]=false;
//         ansprime[1]=false;
//     }
//     for (auto prime : baseprime)
//     {
//         int actual_ans = (l / prime) * prime;
//         if (actual_ans < l)
//         {
//             actual_ans += prime;
//         }
//         int j = max(actual_ans, prime * prime);
//         while (j <= r)
//         {

//             ansprime[j - (l-1)] = false;
//             j += prime;
//         }
//     }
//     return ansprime;
// }
// int mulofprime()
// {
//     int l = 1;
//     int r = 10;
//     vector<bool> print = primelowerandhigher(l, r);
//     int mul = 1;
//     for (int i = 0; i < print.size(); i++)
//     {
//         if (print[i])
//             // cout << (l-1) + i << " ";
//             mul *= ((l-1) + i);
//     }
//     return mul;
// }
class Solution
{
public:
    vector<bool> primeOptimized(long long n)
    {
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i <= n; i++)
        {
            int j = i * i;
            while (j <= n)
            {
                prime[j] = false;
                j += i;
            }
        }
        return prime;
    }
    vector<bool> primelowerandhigher(long long l, long long r)
    {
        vector<bool> seive = primeOptimized(sqrt(r));
        vector<long long> baseprime;
        for (int i = 0; i < seive.size(); i++)
        {
            if (seive[i])
                baseprime.push_back(i);
        }
        vector<bool> ansprime(r - l + 1, true);
        // if (l == 1 || l == 0)
        // {
        //     ansprime[l] = false;
        // }
        if (l == 1)
        {
            ansprime[0] = false;
            ansprime[1] = false;
        }
        for (auto prime : baseprime)
        {
            long long actual_ans = (l / prime) * prime;
            if (actual_ans < l)
            {
                actual_ans += prime;
            }
            long long j = max(actual_ans, prime * prime);
            while (j <= r)
            {

                ansprime[j - l] = false;
                j += prime;
            }
        }
        return ansprime;
    }

    long long primeProduct(long long l, long long r)
    {
        // code here
        int x=1000000007;
        vector<bool> print = primelowerandhigher(l, r);
       long long mul = 1;
        if (l ==0 || l==1)
            mul = 2;
        for (int i = 0; i < print.size(); i++)
        {
            if (print[i])
            {
                cout << l+ i << " ";
                mul=(mul*(l+i))%x;
                // cout<<print[i]<<" ";
            }
        }
        cout<<endl;
        return mul;
    }
};
int main()
{
    // int n = 25;

    // vector<int> ans = primeOptimized(n);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     if (ans[i])
    //         cout << i << " ";
    // }
    // cout << mulofprime();
    // mulofprime();
    Solution s;
    int l = 10;
    int r = 500;
    cout << s.primeProduct(l, r);

    return 0;
}
