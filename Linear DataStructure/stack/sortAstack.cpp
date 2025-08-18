#include<iostream>
#include<stack>
using namespace std;
void insertSort(stack<int> &st ,int target)
{
    //base case
    if(st.empty())
    {
        st.push(target);
        return ;
    }
    if(target <=st.top())
    {
        st.push(target);
        return ;
    }
    int topelement = st.top();
    st.pop();
    insertSort(st,target);
    //backtracking 
    st.push(topelement);
}
void sortStack(stack<int> &st)
{
    //base case
    if(st.empty())
    {
        return;
    }
    int topelement=st.top();
    st.pop();
    sortStack(st);

    insertSort(st,topelement);
}
int main()
{
    stack<int> st;
    st.push(5);
    st.push(3);
    st.push(9);
    st.push(7);
    sortStack(st);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}