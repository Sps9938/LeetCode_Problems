#include<iostream>
using namespace std;
class Solution {
public:
bool istrueornot(string &t)
{
    for(int k=0;k<t.size();k++)
    {
        for(int l=k;l<t.size()-1;l++)
        {
            if(t[k]==t[l+1])
            {
                return false;
            }
        }
    }
    return true;
}
    int lengthOfLongestSubstring(string s) {
        string ans="";
        int i,j;
        for(i=0;i<s.size();i++)
        {
            for(j=i;j<s.size();j++)
            {
                string t=s.substr(i,j-i+1);
                if(istrueornot(t))
                {
                    ans=t.size()>ans.size()?t:ans;
                }
            }
        }
        return ans.size();
    }
};
int main()
{
    Solution s1,s2;
    string s;
    getline(cin,s);
    int c=s1.lengthOfLongestSubstring(s);
    cout<<c;
    return 0;
}