// Online C++ compiler to run C++ program online
#include <iostream>
#include<string.h>
using namespace std;
 bool isValid(string s) {
        string s1="abc";
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==s1[j])
            {
                j++;
            }
            else{
                j=0;
                i--;
            }
            if(j>s1.size())
            {
                s.erase(i-2,3);
                i=-1;
                j=0;
            }

        }
        if(s.empty())
            return true;
        else
            return false;
    }
int main() {
    // Write C++ code here
  string s="aabcbc";
  cout<<isValid(s);

    return 0;
}