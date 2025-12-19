#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxLen = 0;
        int r = 0, l = 0;
        unordered_map<int, int> basket;
        while(r < fruits.size()){
            basket[fruits[r]]++;
            if(basket.size() > 2){
                basket[fruits[l]]--;
                if(basket[fruits[l]] == 0) basket.erase(fruits[l]);
            l++;
            }

            if(basket.size() <= 2){
                int len = r - l + 1;
                maxLen = max(len, maxLen);
            }

            r++;
        }

        return maxLen;
    }
};

/*class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxLen = 0;
        int r = 0, l = 0;
        unordered_map<int, int> basket;
        while(r < fruits.size()){
            basket[fruits[r]]++;
            if(basket.size() > 2){
                while(basket.size() > 2){
                    basket[fruits[l]]--;
                    if(basket[fruits[l]] == 0) basket.erase(fruits[l]);
                    l++;
                }
            }

            if(basket.size() <= 2){
                int len = r - l + 1;
                maxLen = max(len, maxLen);
            }
            r++;
        }

        return maxLen;
    }
};
*/
/*class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxLen = 0;
        for(int i=0;i<fruits.size();i++){
            set<int> st;
            for(int j=i;j<fruits.size();j++){
                st.insert(fruits[j]);
                if(st.size() <= 2){
                    int len = j - i + 1;
                    maxLen = max(len, maxLen);
                }
            }
        }

        return maxLen;
    }
};
*/

int main(){
    Solution s;
    vector<int> fruits = {1,2,3,2,2};
    cout<<"Total Collection of Fruits are: "<<s.totalFruit(fruits);
    return 0;
}