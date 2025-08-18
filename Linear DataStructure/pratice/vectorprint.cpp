#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n=5;
    vector<bool> ans(n+1,true);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}