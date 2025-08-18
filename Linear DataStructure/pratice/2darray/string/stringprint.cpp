#include <iostream>
#include <string.h>
using namespace std;
void print()
{
    //compare
    string str1;
    getline(cin,str1);
    string str2;
    getline(cin,str2);
    if(str1.compare(str2)==0)
        cout<<"Matchig"<<endl;
    else
        cout<<"Not matching"<<endl;
    // string name="tanusree will marry to sps";
    // string str="spssss";
    // if(name.find(str) == string :: npos)
    // {
    //     cout<<"Not found"<<endl;
    // }
    // else
    //  cout<<"found"<<endl;
    





    // string name;
    // // cin>>name;
    // getline(cin, name);
    // // cout << name << endl;
    // // cout << "first index is:" << name[0] << endl;
    // int i=0;
    // while(name[i] != '\0')
    // {
    //     cout<<"At index:"<<i<<" "<<name[i]<<endl;
    //     i++;
    // }
    // int value=(int)name[i];
    // cout<<"At index:"<<i<<" "<<value<<endl;


}
int main()
{
    print();
    return 0;
}