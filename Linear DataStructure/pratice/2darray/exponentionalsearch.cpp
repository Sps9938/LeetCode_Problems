#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int bs(vector<int> &nums,int s,int e,int &target)
    {
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                s=mid+1;
            else 
                e=mid-1;
        }
        return -1;
    }
    int expsearch(vector<int> &nums,int &target)
    {
        if(nums[0]==target)
            return 0;
        int i=1;
        int n=nums.size();
        while(i<n && nums[i]<=target)
        {
           i=i<<1;
        }
        return bs(nums,i/2,min(i,n-1),target);
    }
    
    // int bs(vector<int> &nums,int &target)
    // {
    //     int n=nums.size();
    //     int s=0;
    //     int e=n-1;
    //     while(s<=e)
    //     {
    //         int mid=s+(e-s)/2;
    //         if(nums[mid]==target)
    //             return mid;
    //         else if(target>nums[mid])
    //            s=mid+1;
    //         else 
    //             e=mid-1;
    //     }
    //     return -1;
    // }
    int search(vector<int>& nums, int &target) {
        return expsearch(nums,target);
    }
};
int main()
{
    Solution s;
    vector<int> v{1,2,3,4,8,9,13,14,16,19,30};
    int target=16;
    cout<<s.search(v,target);
    return 0;
}