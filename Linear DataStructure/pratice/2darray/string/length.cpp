#include<iostream>
using namespace std;
void length()
{
    int i=0;
    char ch[100];
    cin.getline(ch,100);
    while(ch[i] != '\0')
    {
        i++;

    }
    cout<<"length of string is:"<<i<<endl;

}
int main()
{
    length();
    return 0;
}