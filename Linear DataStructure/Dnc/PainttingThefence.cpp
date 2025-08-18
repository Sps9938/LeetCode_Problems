#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    long long MOD=1000000007;
    long long CountAns( long long n,vector<long long> &ans, long long k)
    {
        if(n==1)
            return k % MOD;
        if(n==2)
            return (k+(k*(k-1)) % MOD) % MOD;
        if(ans[n]!=-1)
            return ans[n];
        //recursive call
       ans[n]= ((k-1) * (CountAns(n-2,ans,k) + CountAns(n-1,ans,k) ) % MOD) % MOD;
       return ans[n];
    }
    long long countWays(int n, int k){
        // code here
        //base case
        // if(n==0)
        //     return 0;
        vector<long long> ans(n+1,-1);
        return CountAns(n,ans,k);
    }
};
int main()
{
    Solution s;
    long long n;
    cin>>n;
    long long k;
    cin>>k;
    cout<<s.countWays(n,k);
}