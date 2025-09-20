
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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        int height = max(leftHeight, rightHeight) + 1;

        return height;
    }
};


int main() {

	  TreeNode* root = createTree();
	  //cout << root->data << endl;
	 Solution s1;
    cout<<"maxDepth ot Tree is: "<<s1.maxDepth(root)<<endl;

  return 0;
}