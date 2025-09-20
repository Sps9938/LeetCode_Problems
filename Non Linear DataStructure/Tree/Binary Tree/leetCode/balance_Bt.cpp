
#include <iostream>
#include<queue>
using namespace std;

class TreeNode{
  public:
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
	  this->data = val;
	  this->left = NULL;
	  this->right = NULL;
	}


};

//it returns root TreeNode of the created tree
TreeNode* createTree() {
  cout << "enter the value for Node: " << endl;
  int data;
  cin >> data;

  if(data == -1) {
	return NULL;
  }
  //Step1: create Node
  TreeNode* root = new TreeNode(data);
  //Step2: Create left subtree
  //cout << "left of Node: " << root->data << endl;
  root->left = createTree();
  //Step3: Craete right subtree
  //cout << "right of Node: " << root->data << endl;
  root->right = createTree();
  return root;

}
class Solution {
public:
    bool flag = false;
private:
    int maxDepth(TreeNode*& root){
        if(root == NULL) return 0;

        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        if(abs(leftHeight-rightHeight) > 1) flag= true; 

        return max(leftHeight, rightHeight) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

       maxDepth(root);
       if(flag) return false;
        return true;
    }
};


int main() {
//5 10 9 -1 -1 4 -1 -1 6 8 -1 -1 7 -1 -1
// 1 2 3 4 -1 -1 4 -1 -1 3 -1 -1 2 -1 -1
	  TreeNode* root = createTree();
	  //cout << root->data << endl;
	 Solution s1;
    cout<<"isBalanced: "<<s1.isBalanced(root)<<endl;

  return 0;
}