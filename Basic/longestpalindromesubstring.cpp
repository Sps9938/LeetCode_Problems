#include<iostream>
#include<string.h>
using namespace std;
class Solution {
public:
    bool isPalinedrome(string &s,int start,int end)
        {
            while(start<end)
                {
                    if(s[start]!=s[end])
                    {
                        return false;
                    }
                }
            return true;
        }
    string longestPalindrome(string s) 
    {
        string ans="";
        int i,j;

        for(i=0;i<s.size();i++)
            {
                for(j=i;j<s.size();j++)
                    {
                        if(isPalinedrome(s,i,j))
                        {
                            string t=s.substr(i,j-i+1);
                            ans=t.size()>ans.size()?t:ans;
                        }
                    }
            }
            return ans;
    }
};
int main()
{
    Solution s1,s2;
    string s,k;
    getline(cin,s);
    k=s1.longestPalindrome(s);
        cout<<k;
    
    return 0;
        
   
}
/*#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    string s,pre,next;
    int b,c;
    getline(cin,s);
    // for(int i=0;i<s.length()-1;i++)
    // {
    //     pre=s.substr(0,i+1);
        int size=s.length();
        // next=s.substr(0,i+2);
        for(int j=0;j<size-1;j++)
        {
        if(s[j]!=s[size-1] )
            {
                b=0;
               break;
            }
            else
                b=s.length();
            size--;
        }

        // if(next[i]!=next[next.length()-1])
        //     {
        //         c=0;
        //     }
        //     else
        //         c=next.length();
        // if(b<c)
        // {
        //     pre=next;
        //     return c;
        // }
        // else
        //     {
        //         return b;
        //     }

        
    // }
    cout<<b;
    return 0;
}*/