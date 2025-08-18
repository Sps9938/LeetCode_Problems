#include <iostream>
using namespace std;
bool isPalindrome(string &s, int l, int r)
{
    if(l>=r)
        return true; 
   if(s[l]!=s[r])
     return false;
    return isPalindrome(s,l+1,r-1);
}
int main()
{
    string s;
    cin >> s;
    string s1 = s;
    // int l = 0;
    // int r = s.size() - 1;
    // Palindrome(s, l, r);
    // cout << s << endl;
    // if (s1 == s)
    //     cout << "Palindrome" << endl;
    // else
    //     cout << "Not Palindrome";
    cout<<isPalindrome(s,0,s.size()-1);
}