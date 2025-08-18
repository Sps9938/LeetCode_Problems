#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

bool isvalid(vector<int> &arr, int &p, int &mid)
{
    // cout << mid << endl;
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        int k = 1;
        while (sum + arr[i] * k <= mid)
        {
            sum += arr[i] * k;

            k++;
            count++;
            if (count == p)
                return true;
        }
    }
    return false;
}
int bs(vector<int> &arr, int &p)
{
    int s = 0;
    int maxrank = *max_element(arr.begin(), arr.end());
    int minute = (p * (p + 1)) / 2;
    int e = maxrank * minute;
    // cout<<e<<endl;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (isvalid(arr, p, mid))
        {
            ans = mid;
            // cout<<ans<<endl;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return ans;
}
int main()
{

    // cout<<"Enter cases"<<endl;
    // cin>>cases;

    int casses;
    // cout << "Enter no. of casses" << endl;
    cin >> casses;
    while (casses--)
    {
        vector<int> arr;
        int prata;
        // cout << "Enter prata" << endl;
        cin >> prata;
        int cook;
        // cout << "Eneter no. of cook" << endl;
        cin >> cook;

        //     cout<<"Enter no.of cook"<<endl;
        //     cin>>cook;

        while (cook--)
        {
            int rank;

            // cout << "Decide the rank" << endl;
            cin >> rank;
            arr.push_back(rank);
        }
        // cout << "minimum time taken for making prata" << endl;
        cout << bs(arr, prata);
        cout << endl;
    }
    return 0;
}