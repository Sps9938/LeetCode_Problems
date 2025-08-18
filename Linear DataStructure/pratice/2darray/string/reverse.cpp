#include <iostream>
using namespace std;
void length()
{

    char ch[100];
    cin.getline(ch, 100);
    int length = 0;
    while (ch[length] != '\0')
    {
        length++;
    }
    int left = 0;
    int right = length - 1;
    while (left <= right)
    {
        swap(ch[left], ch[right]);
        left++;
        right--;
    }
    cout << "reverse of string is:" << ch << endl;
}
int main()
{
    length();
    return 0;
}