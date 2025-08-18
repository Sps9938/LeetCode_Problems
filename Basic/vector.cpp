#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(9);
   
    for(int i=3;i<6;i++)
    {
        int d;
        cin>>d;
        v.push_back(d);
    }
    v.pop_back();
    v.pop_back();
   
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl<<v.size();
    return 0;
}