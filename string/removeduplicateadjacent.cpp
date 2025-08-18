
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s, int k) {
        // string temp="";
        // int c=1;
        // for(int i=0;i<s.length();i++)
        // {

        //     if(temp.empty() || s[i] != temp[temp.length()-1])
        //         {
        //             temp.push_back(s[i]);\
        //             c=1;
        //         }
        //         else
        //             {
        //                  c++;
        //             if(c==k)
        //             {
        //                 while(--c)
        //                 {
        //                     temp.pop_back();
        //                 }
        //                 c=1;
        //             }
        //             else
        //             {
        //               temp.push_back(s[i]);

        //             }

                   
                    
        //             }
        // }
        int c=1;
        int i=0;
       while(i<s.length()-1)
        {
            if(s[i]==s[i+1])
                {
                    c++;
                    if(c==k)
                    {
                        s.erase(c-i,k);
                        c=1;
                        i=-1;
                    }
                    
                }
                else
                {
                    c=1;
                    
                }
           
                i++;

        }
        return s;
        
    }
};
    // string removeDuplicates(string s)
    //     {
    //     int j = 0;
    //     int l = s.length();
    //     while (j < l - 1)
    //     {
    //         if (s[j] == s[j + 1])
    //         {
    //             s.erase(j,2);
    //             j = 0;
    //         }
    //         else
    //             j++;
    //     }
    //     return s;

    //  string temp="";
    //     for(int i=0;i<s.length();i++)
    //     {
    //         if(s[i]!=temp[temp.length()-1])
    //             temp.push_back(s[i]);
    //         else
    //             temp.pop_back();
    //     }
    //     return temp;
    
  
//     }
// };
int main()
{
    Solution s1;
    string s;
    getline(cin, s);
    int k=2;
    cout << s1.removeDuplicates(s,k)<<endl;
 

    return 0;
}