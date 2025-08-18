#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<char> st;
        int count = 0;
        for (char ch : path)
        {

            if (!st.empty() && ch == '.')
            {
                count += 1;
            }
            if (count == 1 && st.top() != '/' && ch != '/')
            {
                count = 0;
            }

            else if (!st.empty() && ch == '/' && st.top() == '/')
            {
                st.pop();
            }
            else if (!st.empty() && (ch == '/' && st.top() == '.'))
            {
                if (count == 2)
                {
                    while (count--)
                    {
                        st.pop();
                    }
                    st.pop();
                    while (!st.empty() && st.top() != '/')
                    {
                        st.pop();
                    }
                    if (!st.empty())
                        st.pop();
                    count = 0;
                }
                else if (count == 1)
                {
                    while (count--)
                    {
                        st.pop();
                    }
                    st.pop();
                    count = 0;
                }
                else
                {
                    count = 0;
                }
            }
            st.push(ch);
        }

        if (st.top() == '.' && count == 2)
        {
            while (count--)
            {
                st.pop();
            }
            st.pop();
            while (!st.empty() && st.top() != '/')
            {
                st.pop();
            }
            if (!st.empty())
                st.pop();
            count = 0;
        }
        else if (st.top() == '.' && count == 1)
        {
            while (count--)
            {
                st.pop();
            }
            st.pop();
            count = 0;
        }

        if (st.size() > 1)
        {
            if (st.top() == '/')
            {
                st.pop();
            }
        }
        string ans = "";
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        if (ans[0] != '/')
            ans = '/' + ans;

        return ans;
    }
};
int main()
{
    Solution s;
    string input;
    cin>>input;
    cout<<s.simplifyPath(input);
    return 0;
}