#include<iostream>
using namespace std;
#include<math.h>
#define INT_MAX pow(2,31)-1
#define INT_MIN -pow(2,31)
class Solution {
public:
    bool isPalindrome(int x)
        {
            bool b;
            int y=x,rem;
            long p=0;
            // int sign;
            // if(x<0)
            // {
            //      sign=-1;

            // }
            // else
            //     sign=1;
            //  if(sign==1)
             
            while(y!=0)
                {
                    rem=y%10;
                    p=p*10+rem;
                    y=y/10;
                }
             
            if(x==p && x>=0 && x>=INT_MIN && x<=INT_MAX)
            {
                b=true;
            }
            else 
                b=false;
            return b;
        }
};
int main()
{
    Solution s1;
    int x;
    cin>>x;
    bool b=s1.isPalindrome(x);
    cout<<b;
    return 0;
}