#include <iostream>
#include <stack>
using namespace std;
void middleElement(stack<int> &st, int size)
{
    if ((size / 2) + 1 == st.size())
    {
        cout << "Middle element is: " << st.top();
        return;
    }
    int temp = st.top();
    st.pop();
    middleElement(st, size);
    st.push(temp);
}
int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    if (st.size() == 0)
        cout << "stack is empty no middle element present" << endl;
    middleElement(st, st.size());
}