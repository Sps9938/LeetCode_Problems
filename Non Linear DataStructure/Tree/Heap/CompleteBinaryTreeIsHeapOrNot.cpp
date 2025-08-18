#include<iostream>
#include<limits.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(){
        
    }
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;

    }
    pair<bool, int> Solve(Node* root){


        if(root == NULL){
            pair<bool, int> p = make_pair(true, INT_MIN);
            return p;
        }

        if(root->left == NULL && root->right == NULL){
            pair<bool,int> p = make_pair(true, root->data);
            return p;
        }

        pair<bool, int> leftAns = Solve(root->left);
        pair<bool, int> rightAns = Solve(root->right);

        if(leftAns.first == true && rightAns.first == true
         && root->data > leftAns.second && root->data > rightAns.second)
        {
            pair<bool, int> p = make_pair(true, root->data);
            return p;
        }
        else{
            pair<bool, int> p = make_pair(true, root->data);
            return p;
        }


        }
};


int main(){


    return 0;
}