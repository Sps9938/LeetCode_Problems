#include <iostream>
using namespace std;
int main()
{
    int i, j, n;
    cin >> n;
    char ch;
    // int k=2*n-1;
    for (i = 0; i < n; i++)
    {
        ch='A';
        for (j = 0; j < n; j++)
        {

            if (i >= j)
                {
                    cout<<ch;
                    ch++;
                    
                }
            else
                cout<<" ";
        }
        cout << endl;
    }
    return 0;
}