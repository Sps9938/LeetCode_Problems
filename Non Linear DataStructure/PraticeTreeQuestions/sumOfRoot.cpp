#include <iostream>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode()
    {
    }
    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    TreeNode *Creation()
    {
        int data;
        cout << "Enter data" << endl;
        cin >> data;
        if (data == -1)
            return NULL;

        TreeNode *root = new TreeNode(data);
        root->left = Creation();
        root->right = Creation();
        return root;
    }
};
int AddRoot(TreeNode *root)
{
    // root->data = leftsum + root->data + rightsum
    if (root == NULL)
        return 0;
    int leftSum = AddRoot(root->left);
    int rightSum = AddRoot(root->right);
    return root->data = leftSum + root->data + rightSum;
}

int ans = -1;
int Ansector(TreeNode *root, int &k, int node)
{
    if (root == NULL)
        return 0;

    if (root->data == node)
    {

        return root->data;
    }

    int leftAns = Ansector(root->left, k, node);
    int rightAns = Ansector(root->right, k, node);
    // cout << "leftAns= " << leftAns << endl;
    // cout << "rightAns= " << rightAns << endl;
    if (leftAns)
    {
        k = k - 1;
        if (k == 0)
        {
            ans = root->data;
            return 0;
        }
        return root->data;
    }

    else
        return 0;
}
int kthAncestor(TreeNode *root, int k, int node)
{
    // Code here
    Ansector(root, k, node);
    if (k == 0)
        return ans;
    return -1;
   
}
int main()
{
    TreeNode t1;
    TreeNode *root = t1.Creation();
    // cout << "The Sum of Root is: " << endl;
    // cout << AddRoot(root);
    // 10 20 40 60 -1 -1 70 -1 -1 50 -1 -1 30 -1 90 -1 -1
    // 1 2 4 -1 -1 5 -1 -1 3 -1 -1
    //1 2 3 -1 4 5 -1 -1 -1 6 -1 -1 7 -1 -1
    cout << endl;
    cout << "kthAnsector: "<<kthAncestor(root, 1, 2);
   
    return 0;
}