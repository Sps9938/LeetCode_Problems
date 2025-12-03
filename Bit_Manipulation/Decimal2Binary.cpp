#include<bits/stdc++.h>
using namespace std;
string convertDecimalToBinary(int x){
    string ans = "";
    while(x != 1){
        int d = x%2;
        if(d == 1) ans += '1';
        else ans += '0';

        x = x/2;
    }
    ans += '1';
    reverse(ans.begin(), ans.end());
    return ans;
}
int convertBinaryToDecimal(string ans){
    int pow2 = 0;
    int n = ans.length()-1;
    int x = 0;
    int i = 0;
    for(int index=ans.length()-1;index>=0;index--){
        if(ans[index] == '1'){
            pow2 = pow(2, i);
            x = x+pow2;
        }
        i++;
    }

    return x;
}

int main(){

    int x = 15;
    string ans = convertDecimalToBinary(x);
    cout<<"Binary is: ";
    for(int i=0;i<ans.length();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    int n = convertBinaryToDecimal(ans);
    cout<<"Decimal is: "<<n<<endl;

    return 0;
}