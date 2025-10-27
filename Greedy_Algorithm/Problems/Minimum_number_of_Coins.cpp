#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findMin(int n) {
        // code here
        int arr[] = {10, 5, 2, 1};
        int count = 0;
        for(int i=0;i<4;i++){
            int rup = arr[i];
            if(rup <= n){
                int poss = n/rup;
                n -= rup*poss;
                count += poss;
                if(n == 0) break;
            }
        }
        return count;
    }
};
int main(){
    Solution s;
    int n = 39;
    cout<<"minimum number of coins is: "<<s.findMin(n);

    return 0;
}