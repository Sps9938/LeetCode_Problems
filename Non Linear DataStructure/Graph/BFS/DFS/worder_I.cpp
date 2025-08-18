class Solution {
private:
    int solveUsingBFS(string startWord, string endWord, unordered_set<string>& st){

        /*
            T.C = O(n * (l*26)) = O(n*l) | S.C = O(n*l)
            n-> wordList length
            l-> one word length
        */
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        
        while(!q.empty()){
            auto topString = q.front();
            q.pop();
            string beginWord = topString.first;
            int totalPath = topString.second;

            if(beginWord == endWord) return totalPath;

            for(int index=0; index<beginWord.length(); index++){
                char backtrack = beginWord[index];
                for(char ch='a';ch<='z';ch++){
                    beginWord[index] = ch;
                    if(st.find(beginWord) != st.end()){
                        q.push({beginWord, totalPath+1});
                        st.erase(beginWord);
                    }
                }
                beginWord[index] = backtrack;
            }


        }
        return 0;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        return solveUsingBFS(beginWord, endWord, st);
    }
};
/*
class Solution {
private:
    int solveUsingBFS(string beginWord, string endWord, vector<string>& ansList){
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        while(!q.empty()){
            auto frontWord = q.front();
            q.pop();
            string word = frontWord.first;
            int wordCount = frontWord.second;

            if(word == endWord) return wordCount;

            for(int i=0;i<word.length();i++){
                char intia = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    cout<<"word is"<<word<<endl;
                    for(int j=0;j<ansList.size();j++){
                        if(ansList[j] == word){
                            q.push({ansList[j], wordCount+1});
                            ansList[j] = "";
                        }
                    }
                }
                word[i] = intia; 
            }
        }
        return 0;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> ansList = wordList;
        return solveUsingBFS(beginWord, endWord, ansList);
    }
};
*/