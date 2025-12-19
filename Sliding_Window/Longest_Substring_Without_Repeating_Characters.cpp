#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        fill(begin(hash), end(hash), -1);
        int l=0, r=0, maxLen = 0;

        while(r < s.length()){
            if(hash[s[r]] != -1 && hash[s[r]] >= l) l = hash[s[r]]+1;
            hash[s[r]] = r;
            int len = r - l + 1;
            maxLen = max(len, maxLen);
            r++;
        }

        return maxLen;
    }
};
int main(){
    Solution s;
    string s1 = "abcabcbb";
    cout<<"Length of longest Substring: "<<s.lengthOfLongestSubstring(s1);
    return 0;
}