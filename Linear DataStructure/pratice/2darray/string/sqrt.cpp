#include <iostream>
using namespace std;
int squareroot(int n)
{
    int s = 0;
    int e = n;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (mid * mid <= n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return ans;
}
double precession(int n)
{
    double sqrt = squareroot(n);
    double step = 0.1;
    for (int i = 0; i < 5; i++)
    {
        double j = sqrt;
        while (sqrt * sqrt <= n)
        {
            sqrt = sqrt + step;
            // sqrt=j;
            // j+=step;
        }
        sqrt -= step;
        step = step / 10;
    }
    return sqrt;
}
int main()
{
    int n;
    cin >> n;
    // cout<<precession(n);
    printf("%10f", precession(n));
    return 0;
}