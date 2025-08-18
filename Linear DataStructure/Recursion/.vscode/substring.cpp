#include <iostream>
using namespace std;
void substring(string &s, int start, int end)
{
    // base caee
    if (end >= s.size())
        return;
    // recursive case
    for (int i = start; i <= end; i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
    substring(s, start, end + 1);
}
void subarray_util(string &s)
{
    for (int start = 0; start < s.size(); start++)
    {
        int end=start;
        substring(s, start, end);
    }
}
int main()
{
    string s;
    cin >> s;
    subarray_util(s);
}