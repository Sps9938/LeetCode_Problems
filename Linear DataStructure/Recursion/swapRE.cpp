#include<iostream>
#include<string.h>
using namespace std;
void reversestring(string &s,int l,int r)
{
    if(l>r)
        return ;
    swap(s[l],s[r]);
    reversestring(s,l+1,r-1);
}
int main()
{
    string s;
    getline(cin,s);
    int l=0;
    int r=s.size()-1;
    reversestring(s,l,r);
    cout<<s;
    return 0;
}