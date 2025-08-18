#include <iostream>
using namespace std;
void uppercase(char ch[],int &l)
{

    for(int i=0;i<l;i++)
    {
        if(ch[i]>='a' && ch[i]<= 'z')
        {
            ch[i]=ch[i]-32;
        }
    }
    cout<<ch<<endl;
}
void lowercase(char ch[],int &l)
{
    for(int i=0;i<l;i++)
    {
        if(ch[i]>='A' && ch[i]<= 'Z')
        {
            ch[i]=ch[i]+32;
        }
    }
    cout<<ch<<endl;
}
int main()
{
    char ch[100];
    cin.getline(ch, 100);
    int l=0;
    while(ch[l] !='\0')
    {
        l++;
    }
    
   uppercase(ch,l);
    return 0;
}