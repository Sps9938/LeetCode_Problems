#include <iostream>
using namespace std;
int quitentans(int &n, int &d)
{
    int s = 0;
    int e = n;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (mid * d <= n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return ans;
}
double precessionvalue(int &n, int &d)
{
    double ans = quitentans(n, d);
    double step = 0.1;
    for (int i = 0; i < 5; i++)
    {
        double j = ans;
        while (j * d <= n)
        {
            ans = j;
            j += step;
        }
        step = step / 10;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int d;
    cin >> d;
    cout << precessionvalue(n, d);
    return 0;
}