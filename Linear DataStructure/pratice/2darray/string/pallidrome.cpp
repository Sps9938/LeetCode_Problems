#include <iostream>
using namespace std;
void palindrome(char ch[],int l)
{
  int left=0;
  int right=l-1;
  int ans=0;
  while(left<=right)
  {
    if(ch[left]!=ch[right])
        {
            ans=1;
            break;
        }
        left++;right--;
  }
  if(ans==0)
    cout<<"string is a palinrome"<<endl;
  else 
   cout<<"Not palindrome"<<endl;


}
int main()
{
    char ch[100];
    cin.getline(ch, 100);
    int l=0;
    while(ch[l] !='\0')
    {
        l++;
    }
    
   palindrome(ch,l);
    return 0;
}