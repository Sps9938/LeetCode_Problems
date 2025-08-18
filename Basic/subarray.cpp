#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:

   int  findMaxLength(vector<int>& nums) {
        int i,n;
        cin>>n;
        for(i=0;i<n;i++)
        {
            int x;
            cin>>x;
            nums.push_back(x);
        }
        for(i=0;i<nums.size()-1;i++)
        {
           cout<<"("<<nums[i]<<","<<nums[i+1]<<")"<<endl; 
        }
        // cout<<i;
        return nums.size()-1;
        
    }
};
int main()
{
    Solution s;
    vector <int> v;
   
    int x;
    x=s.findMaxLength(v);
    cout<<x;
}
/*#include<iostream>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(i=0;i<n-1;i++)
    {

    }
    cout<<i;
    return 0;

}*/