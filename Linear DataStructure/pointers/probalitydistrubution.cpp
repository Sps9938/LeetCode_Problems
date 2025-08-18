#include <iostream>
#include <math.h>
using namespace std;
double probalbilitdistrubution(int n, int r)
{
    if (n >= r)
    {
        double x = n - r;
        // factorial of n is:
        double factofN = 1;
        for (int i = 1; i <= n; i++)
        {
            factofN = factofN * i;
        }
        // factorial of n-r=x:
        double factofX = 1;
        for (int i = 1; i <= x; i++)
        {
            factofX = factofX * i;
        }
        // factorial of r:
        double factofR = 1;
        for (int i = 1; i <= r; i++)
        {
            factofR = factofR * i;
        }
        double combination = (factofN / (factofX * factofR));
        // here left step(p)=rigt step(q)
        // so,p=q=0.5
        double p = 0.5;
        double q = 0.5;
        double bd = combination * pow(p, r) * pow(q, n - r);
        return bd;
    }
}
int main()
{
    int n;
    cout << "Enter the No. of walk" << endl;
    cin >> n;
    int r;
    cout << "Probality of getting exactly how many sucessor" << endl;
    cin >> r;
    cout << "Problability distrubution is: " << probalbilitdistrubution(n, r);
    return 0;
}
