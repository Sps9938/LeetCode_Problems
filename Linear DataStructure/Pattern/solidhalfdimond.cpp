#include <iostream>
using namespace std;
int main()
{
    int i, j, n;
    cin >> n;
    int k = 2 * n;
    int l = n + 1;
    for (i = 0; i < n; i++)
    {

        for (j = 0; j <= 2 * n; j++)
        {
            if (i >= j && j <= n - 1)
                cout << "*";

            else if (k <= j)
                cout << "*";
            else

                cout << " ";
        }

        cout << endl;
        k--;
    }
    for (i = n; i > 0; i--)
    {

        for (j = 0; j <= 2 * n; j++)
        {

            if (i > j && j <= n - 1)
                cout << "*";
            else if (l <= j)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
        l++;
    }
}