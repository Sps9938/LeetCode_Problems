#include<iostream>
using namespace std;
class TierNode{

    public: 
        char ch;
        TierNode* children[26];
        bool terminal;
    TierNode(char ch){
        this->ch = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        terminal = false;
    }
};

void deletion(TierNode* root, string s){
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
bool serching(TierNode* root, string s){
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
void insert(TierNode* root, string s){
    //base case
    // cout<<"string is: "<<s<<endl;
    if(s.length() == 0) {
        root->terminal = true;
        return;
    }


    //1st getting 
    TierNode* child;
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
        child = new TierNode(ch);
        root->children[ch-'a'] = child;
        // insert(temp, word);
    }

    insert(child, word);
}

int main(){

TierNode* root = new TierNode('\0');
insert(root,"code");
insert(root,"coder");
insert(root,"coding");
insert(root,"codehelp");

deletion(root, "codehelp");
if(serching(root,"codehelp")){
    cout<<"Present"<<endl;
}
else{
    cout<<"Absent"<<endl;
}
    return 0;
} 