#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> v=matrix;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=i+1;j<matrix[i].size();j++)
            {
                 swap(v[i][j],v[j][i]);
                // v.push_back(matrix[i][j]);
            }
        }
        return v;
    }
};
int main()
{
    vector<vector<int>> v={
       {1,2,3},{4,5,6},{7,8,9}
    };
    vector<vector<int>> tr;
    Solution s;
   tr= s.transpose(v);
   for(int i=0;i<tr.size();i++)
   {
    for(int j=0;j<tr[i].size();j++)
    {
        cout<<tr[i][j]<<" ";
    }
    cout<<endl;
   }
}