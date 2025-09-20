
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
    int d = 0;
private:
    int maxDepth(TreeNode*& root){
        if(root == NULL) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        int currD = left + right;
        d = max(d, currD);
        return max(left, right) + 1;

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        
        //root-> chode ka
        //root->left maxDept + root->right maxDepth

        maxDepth(root);

        return d;
    }
};


int main() {
//4,-7,-3,-1,-1,-9,-3,9,-7,-4,-1,6,-1,-6,-6,-1,-1,0,6,5,-1,9,-1,-1,-1,-4,-1,-1,-1,-2
	  TreeNode* root = createTree();
	  //cout << root->data << endl;
	 Solution s1;
    cout<<"Diameter of Bt is: "<<s1.diameterOfBinaryTree(root)<<endl;

  return 0;
}