#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int> &q, int k)
{

    stack<int> st;
    queue<int> qu;
    int i = 0;
    while (!q.empty())
    {
        int element = q.front();

        if (i >= k)
        {
            qu.push(element);
            q.pop();
        }
        else
        {
            st.push(element);
            q.pop();
        }
        i++;
    }
    while (!st.empty())
    {
        int element = st.top();
        q.push(element);
        st.pop();
    }
    while (!qu.empty())
    {
        int element = qu.front();
        q.push(element);
        qu.pop();
    }
}

void reversek(queue<int> &q, int k)
{
    stack<int> st;
    int n = q.size();
    int count = 0;

      if(k <= 0 || k > n)
        return;

    // 1st k size push into stack
    while (!q.empty())
    {

        int element = q.front();
        st.push(element);
        q.pop();
        count++;
        if (count == k)
        {
            break;
        }
    }

    // 2nd step the top element of stack push into queue
    while (!st.empty())
    {

        int element = st.top();
        q.push(element);
        st.pop();
    }

    // 3rd step pop n-k element ->then push that element parallely on queue
    count = 0;
    while (!q.empty() && n-k != 0)
    {
        // if(k == n)
        //     break;

        int element = q.front();
        q.push(element);
        q.pop();
        count++;
        if (count == n - k)
            break;
    }
}

int main()
{
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(12);
    q.push(15);
    q.push(18);

    // reverseQueue(q, 4);
    reversek(q, 7);
    cout << "Reverse Queue is: " << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}