#include<iostream>
#include<string.h>
using namespace std;
void occurancelefttoright(string s,int i,char x,int &ans)
{
  
    if(i>=s.size())
        return ;
    if(s[i]==x)
        ans=i;
    occurancelefttoright(s,i+1,x,ans);
}
void occurancerighttoleft(string s,int i,char x,int &ans)
{
    if(i<0)
        return;
    if(s[i]==x)
    {
        ans=i;
        return ;
    }
    occurancerighttoleft(s,i-1,x,ans);
}
int main()
{
    string s="xlcdadbdl";
    char x='x';
    int i=0;
    int ans=-1;
    // occurancelefttoright(s,i,x,ans);
    occurancerighttoleft(s,s.size()-1,x,ans);
    cout<<ans;
    return 0;
}