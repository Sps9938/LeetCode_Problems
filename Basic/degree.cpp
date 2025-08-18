#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
   void findShortestSubArray(vector<int>& nums) {
    int i,j,k;
    vector<int> z;
    int n=nums.size();
    for(i=0;i<n-1;i++)
    {
        for(j=i;j<n-1;j++)
        {
            for(k=i;k<j+1;k++)
            {
                // cout<<nums[k];
              if(nums[i]==nums[k+1])

            }
            
            cout<<endl;
        }
        cout<<endl;
    }
        
    }
};
int main()
{
    Solution s1;
    vector<int>v;
    for(int i=0;i<5;i++)
    {
        int d;
        cin>>d;
        v.push_back(d);
    }
    s1.findShortestSubArray(v);
}