#include <iostream>
#include <limits.h>
#include<vector>
using namespace std;
long long brouteforcemethod(int *arr, long long &n, int &m)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }

    long long ans = -1;
    for (int i = 0; i <= max; i++)
    {
        long long sum = 0;
        for (int j = 0; j < n; j++)
        {
            // long long diff = arr[j] - i;
            if (arr[j] > i)
                sum+=arr[j]-i;
        }
        if (sum >= m)
            ans = i;
        else
            return ans;
    }
    return ans;
}
bool ispossible(vector<long long int> &arr,  long long int &m, long long int &mid)
{
    long long sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        // long long diff = arr[i] - mid;
        if (arr[i] > mid)
            sum+=arr[i]-mid;
    }
    if (sum >= m)
            return true;
    return false;
}
long long bs(vector<long long int> &arr, long long int &m)
{
    long long int  s = 0;
    long long int  e = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (e < arr[i])
            e = arr[i];
    }
    long long int ans = -1;
    while (s <= e)
    {
        long long int mid = s + (e - s) / 2;
        if (ispossible(arr, m, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return ans;
}
int main()
{
    vector<long long int> arr;
    long long int n,m;
    cin>>n>>m;
    while(n--)
    {
        long long int h;
        cin>>h;
        arr.push_back(h);
    }
    cout<<bs(arr,m);
    return 0;

}