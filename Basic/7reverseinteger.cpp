#include<iostream>
#include<math.h>
//   # define INT_MAX  pow(2,31)-1
//   # define INT_MIN  -pow(2,31)
using namespace std;
class Solution 
{
public:
    int reverse(int x) 
    {
        int  a;
        long sum = 0;
        int sign, s;
        
        if (x > 0) 
        {
            sign = 1;
        } 
        else
            sign = -1;
        while (x != 0)
         {
            
             
                a = x % 10;
               sum=sum*10+a;
                

                x = x / 10;
               
            
        }
        
        if (sum < 0)
         {
            s = -1;
         } 
         else
            s = 1;
         if(sum>=-2147483648 && sum<=2147483647)
        {
             if (sign == s)
             {
                x=sum;
             }
        } 
        else{
            x=0;
        }  
       
       
        
        return x;

       
    }

};
int main()
{
    Solution s;
    int p, x;
    cin>>x;
   
    // if(x<=-2147483648 || x>=2147483647)
    // {
    //     return 0;
    // }
    // else
        p=s.reverse(x);
        cout<<p;
    
    return 0;
    
}
//acutal solution
class Solution 
{
public:
    int reverse(int x) 
    {
        int  a;
        long sum = 0;
        int sign, s;
        while (x != 0)
         {
                a = x % 10;
               sum=sum*10+a;   
                x = x / 10;
               
        }
         if(sum>=-2147483648 && sum<=2147483647)
        { 
             x=sum;  
        } 
        else
        {
            x=0;
        }  
        return x;
    }
};