#include<iostream>
#include<vector>
using namespace std;
void movenegativenumber(vector<int> &nums)
{
    vector<int> pos,neg,ans;
    int i;
    for(i=0;nums.size();i++)
    {
        if(nums[i]<0)
            neg.push_back(nums[i]);
        // if(nums[i]>0)
        else
            pos.push_back(nums[i]);
        
    }
    for(i=0;i<neg.size();i++)
    {
        ans.push_back(neg[i]);
    }
    for(i=0;i<pos.size();i++)
    {
        ans.push_back(pos[i]);
    }
    nums=ans;
    
};
int main()
{
    vector<int> nums={1,2,-3,4,-5,6};
    movenegativenumber(nums);
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
    return 0;
}