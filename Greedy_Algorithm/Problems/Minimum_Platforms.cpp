#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int count = 0;
        
        int ans = 0;
        int n = arr.size();
        int i=0;
        int j=0;
        while(i < n && j < n){
            if(arr[i] <= dep[j]){
                count++;
                i++;
            }
            else{
                count--;
                j++;
            }
            
            ans = max(ans, count);
        }
        
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout<<"Min platforms is: "<<s.minPlatform(arr, dep);
    return 0;
}
