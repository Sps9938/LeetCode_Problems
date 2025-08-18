#include<iostream>
#include<stack>
using namespace std;
int main()
{
    //creation of stack
    stack<int> st;
    //insrt stack into element
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);


    //delete the element from stack
    st.pop();
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    if(st.empty())
    {
        cout<<"Stack is empty"<<endl;

    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
    return 0;
}