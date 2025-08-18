#include <iostream>
using namespace std;
int main()
{
    int i, j, n, k, m;
    cin >> n;
    int l = n - 1;

    // int k=2*n-1;
    for (i = n - 1; i >= 0; i--)
    {
        k = 1;
        m = n - i - 1;
        for (j = 0; j < 2 * n - 1; j++)
        {

            if (i <= j && j <= n - 1)
            {
                cout << k<<" ";
                k++;
            }
           //taken a variable which has l for fixed and compaire the column
            else if (j <= l && m != 0 && m > 0 && j >= n)
            {

                cout << m<<" ";
                --m;
            }
            else
                cout << " "<<" ";
            l++;
        }
        cout << endl;
    }
}