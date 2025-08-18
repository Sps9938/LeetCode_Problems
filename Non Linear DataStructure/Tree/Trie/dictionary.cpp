#include<iostream>
#include<vector>
using namespace std;
class TrieNode{

    public: 
        char ch;
        TrieNode* children[26];
        bool terminal;
    TrieNode(char ch){
        this->ch = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        terminal = false;
    }
};

void deletion(TrieNode* root, string s){
    //base case
    if(s.length() == 0){
        root->terminal = false;
        return;
    }

    char ch = s[0];
    string word = s.substr(1);
    int index = ch-'a';
    if(root->children[index] != NULL){
        root = root->children[index];
        deletion(root, word);
    }
    else{
        return;
    }
}
bool ans = true;
bool serching(TrieNode* root, string s){
    //base case
    if(s.length() == 0){
        ans = root->terminal;
        return ans;
    }
    char ch = s[0];
    string word = s.substr(1);
    int index = ch-'a';
    if(root->children[index] != NULL){
        //gettting that charater
        root = root->children[index];
        serching(root, word);
    }
    else{
        ans=false;
    }
    return true && ans;
}
void insert(TrieNode* root, string s){
    //base case
    // cout<<"string is: "<<s<<endl;
    if(s.length() == 0) {
        root->terminal = true;
        return;
    }


    //1st getting 
    TrieNode* child;
    char ch = s[0];
    string word = s.substr(1);

    if(root->children[ch-'a'] != NULL){
        //if gettting then ->go to next node
        child = root->children[ch-'a'];
        // insert(root, word);
    }

    //2nd not getting 
    else{
        //create a new node then call substring
        child = new TrieNode(ch);
        root->children[ch-'a'] = child;
        // insert(temp, word);
    }

    insert(child, word);
}

void getSuggestionForGivenInput(TrieNode* root, vector<string> &temp, string &perfix) {


    //base case
    if(root->terminal == true){
        temp.push_back(perfix);
    }


    for(char ch = 'a'; ch<='z'; ch++){
        int index = ch -'a';

        TrieNode* next = root->children[index];

        if(next != NULL){

            perfix.push_back(ch);
            getSuggestionForGivenInput(next, temp, perfix);
            perfix.pop_back();

        }
    }
}

void print(vector<vector<string>> output){
    for(int i=0;i<output.size();i++){
        for(int j=0;j<output[i].size();j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){

vector<string> input;

input.push_back("money");
input.push_back("moon");
input.push_back("mommy");
input.push_back("mother");
input.push_back("monitor");
input.push_back("father");
input.push_back("sister");

//create Trie
TrieNode* root = new TrieNode('\0');
for(int i=0;i<input.size();i++){
    insert(root, input[i]);
}
vector<vector<string>> output;

string  searching = "mot";

TrieNode* prev = root;

string prefix = "";
vector<string> temp;

for(int i=0;i<searching.size();i++){


    char lastChar = searching[i];

    vector<string> temp;
    int index = lastChar-'a';

    TrieNode* curr = prev->children[index];

    if(curr == NULL)
        break;
    else{
        
        prefix.push_back(lastChar);

        getSuggestionForGivenInput(curr, temp, prefix);
        output.push_back(temp);
        prev = curr;
    }
}

print(output);

    return 0;
}