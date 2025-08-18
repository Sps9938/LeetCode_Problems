#include <iostream>
using namespace std;
void StringPermutation(string &s, int index)
{
    // base case
    if (index >= s.length())
    {
        cout << s << " ";
        return;
    }
    for (int j = index; j < s.length(); j++)
    {
        swap(s[index], s[j]);
        // recurssive call
        StringPermutation(s, index + 1);
        // backtracking
        swap(s[index], s[j]);
    }
}
int main()
{
    string s;
    // cin >> s;
    getline(cin, s);
    StringPermutation(s, 0);
}