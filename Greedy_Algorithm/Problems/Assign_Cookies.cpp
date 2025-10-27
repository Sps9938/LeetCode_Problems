#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i=0;
        int j=0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(i < g.size() && j < s.size()){
            if(g[i] <= s[j]){
                i++;
            }
            j++;
        }

        return i;
    }
};

int main(){
    Solution s1;
    vector<int> g = {1,1,3};
    vector<int> s = {1,1};
    cout<<"max got: "<<s1.findContentChildren(g,s);
    return 0;
}