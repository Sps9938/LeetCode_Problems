class Solution {
private:
    void solveUsingBFS(string startWord, string endWord, vector<vector<string>>& ans, unordered_set<string>& st){
        queue<vector<string>> q;
        q.push({startWord});
        int level = 0;

        //to help not repeateing word when word will repace -> here we remove the word if alread exist
        vector<string> usedOnLevel;
        usedOnLevel.push_back({startWord});

        while(!q.empty()){
            vector<string> beginList = q.front();
            q.pop();

            if(beginList.size() > level){
                level++;
                for(auto it : usedOnLevel){
                    st.erase(it);
                }
                usedOnLevel.clear();
            }
          
            string word = beginList.back();

            if(word == endWord){
                if(ans.size() == 0){
                    ans.push_back(beginList);
                }
                else if(ans[0].size() == beginList.size()){
                    ans.push_back(beginList);
                }
            }

            //repace with other character and check if found on wordlIst

            for(int index=0; index<word.length(); index++){
                char orignalChar = word[index];
                for(char ch='a'; ch<='z'; ch++){
                    word[index] = ch;

                    if(st.count(word) > 0){
                        beginList.push_back(word);
                        q.push(beginList);
                        usedOnLevel.push_back(word);
                        beginList.pop_back();
                    }
                }
                word[index] = orignalChar;
            }
        }

    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> st(wordList.begin(), wordList.end());

        solveUsingBFS(beginWord, endWord, ans, st);
        return ans;
    }
};