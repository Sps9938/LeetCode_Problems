/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        vector<int> &temp = v[i];
        // int a, b;
        // a = temp[0];
        // b = temp[1];
        cout << temp[0] << " " << temp[1] << endl;
    }
}
bool mycomp(vector<int>&a,vector<int>&b)
{
    return a[1]>b[1];
}
int main()
{
    vector<vector<int>> v;
    int n;
    cout << "Entet size" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cout << "Enter a&b" << endl;
        cin >> a >> b;
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);
        v.push_back(temp);
    }
    cout<<"Print vector of vector"<<endl;
    print(v);
    sort(v.begin(),v.end(),mycomp);
    cout<<"After sorting vector of vector is:"<<endl;
    print(v);
    return 0;
}*/
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(vector<vector<int>> &arr,int &n)
{
  for(int i=0;i<n;i++)
  {
    vector<int> &temp=arr[i];

    cout<<temp[0]<<" "<<temp[1]<<endl;
  }
}

int main() {
 vector<vector<int>> arr;
 int n;
 cin>>n;
 for(int i=0;i<n;i++)
 {
  vector<int> v;
  int a,b;
  cin>>a>>b;
  v.push_back(a);
  v.push_back(b);
  arr.push_back(v);
 } 
 print(arr,n);

  return 0;
}