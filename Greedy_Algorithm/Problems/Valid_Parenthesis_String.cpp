#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool solveUsingRecursion(string &s, int index, int cnt){

        /*
            T.C = O(3^n) || S.C = O(n)

        */
        //base case
        if(cnt < 0) return false;
        if(index >= s.size()){
            return cnt == 0;
        }

        if(s[index] == '('){
            return solveUsingRecursion(s, index+1, cnt+1);
        }
        else if(s[index] == ')'){
            return solveUsingRecursion(s, index+1, cnt-1);
        }
        else{
            return solveUsingRecursion(s, index+1, cnt+1) || 
            solveUsingRecursion(s, index+1, cnt-1) || 
            solveUsingRecursion(s, index+1, cnt);
        }

        return true;
    }
private:
    bool solveUsingMemo(string &s, int index, int cnt, vector<vector<int>> &dp){

        /*
            T.C = O(n^2) || S.C = O(n^2)

        */

        //base case
        if(cnt < 0) return false;
        if(index >= s.size()){
            return cnt == 0;
        }

        if(dp[index][cnt] != -1) return dp[index][cnt]; 

        if(s[index] == '('){

            dp[index][cnt] = solveUsingMemo(s, index+1, cnt+1, dp);
            return dp[index][cnt];
        }
        else if(s[index] == ')'){
            dp[index][cnt] = solveUsingMemo(s, index+1, cnt-1, dp);
            return dp[index][cnt];
        }
        else{
            dp[index][cnt] =  solveUsingMemo(s, index+1, cnt+1, dp) || 
            solveUsingMemo(s, index+1, cnt-1, dp) || 
            solveUsingMemo(s, index+1, cnt, dp);

            return dp[index][cnt];
        }
    
      dp[index][cnt] = true;
      return dp[index][cnt];
    }
private:
    bool optimalApproach(string &s){
        /*
            T.C = O(n) || S.C = O(1)

        */
        int min_open = 0;
        int max_open = 0;

        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch == '('){
                min_open += 1;
                max_open += 1;
            }
            else if(ch == ')'){
                min_open -= 1;
                max_open -= 1;
            }
            else{
                min_open -= 1;
                max_open += 1;
            }

            
            if(max_open < 0) return false;

            min_open = max(min_open, 0);

        }

        return min_open == 0;
    }
public:
    bool checkValidString(string &s) {
        int index = 0;
        int cnt = 0;
        // return solveUsingRecursion(s, index, cnt);
        // vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, -1));

        // return solveUsingMemo(s, index, cnt, dp);

        return optimalApproach(s);


    }
};

int main(){
    Solution s1;
    string s = "()(*";
    cout<<"is string is valid parentesis: "<<s1.checkValidString(s);
    return 0;
}