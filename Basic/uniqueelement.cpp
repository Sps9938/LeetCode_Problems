#include <iostream>
using namespace std;
// int uniqueelement(int ar[], int size)
// {

//     int unique = 0;
//     for (int i = 0; i < size; i++)
//     {
//         unique = unique ^ ar[i];
//     }
//     cout << "Unique element of an arrya is" << endl;
//     return unique;
// }
void uniquelement(int ar[], int size)
{
        for ( int i = 0; i < size-1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (ar[i] > ar[j])
                    swap(ar[i], ar[j]);
            }
        }
       int f=0;
        while (f < size)
        {
            if (ar[f] == ar[f + 1])
            {
                 f = f + 2;
            }
            else
            {
                cout << "Unique element of an arrya is" << endl;
                cout << ar[f] << endl;
                f=f+1;
            }

        }
}

int main()
{
    int x, size, unique = 0;
    size = 15;
    int i;
    int ar[] = {2, 10, 20, 11, 13, 10, 2, 17, 15, 13, 19, 15, 11, 20, 17};
     uniquelement(ar, size);
    
    return 0;
}
