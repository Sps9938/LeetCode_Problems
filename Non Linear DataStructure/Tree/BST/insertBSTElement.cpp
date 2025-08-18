#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
void PostOrderTraversal(Node *root)
{

    // basse case
    if (!root)
        return;

    // 1st. root left data print
    // 2nd. root right data print
    // 3rd. root data print

    PostOrderTraversal(root->left);

    PostOrderTraversal(root->right);

    cout << root->data << " ";
}
void PreOrderTraversal(Node *root)
{

    // basse case
    if (!root)
        return;

    // 1st. root data print
    // 2nd. root left data print
    // 3rd. root right data print

    cout << root->data << " ";

    PreOrderTraversal(root->left);

    PreOrderTraversal(root->right);
}
void inOrderTraversal(Node *root)
{

    // basse case
    if (!root)
        return;

    // 1st. root left data print
    // 2nd. root data print
    // 3rd. root right data print
    inOrderTraversal(root->left);

    cout << root->data << " ";

    inOrderTraversal(root->right);
}
void levelOrderTreversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            // traverse krna hai
            cout << front->data << " ";
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
    }
}

Node *insertBST(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    // not null
    if (root->data > data)
        root->left = insertBST(root->left, data);
    else
        root->right = insertBST(root->right, data);

    return root;
}
int smallValue(Node *root)
{
    // itreative approach
    Node *temp = root;
    if (temp == NULL)
        return -1;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;

    // recurssive approach
    //  if(root)
    //  {
    //      smallAns = root->data;
    //  }
    //  //base caae
    //  if(root == NULL)
    //  {
    //      return 0;
    //  }

    // return smallValue(root->left, smallAns);
}
int largeValue(Node *root)
{
    // iterative approach
    Node *temp = root;
    if (temp == NULL)
        return -1;

    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;

    // recurrsive approach

    // if(root)
    // {
    //     largeAns = root->data;
    // }
    // //base caae
    // if(root->right == NULL)
    // {
    //     return 0;
    // }

    // return largeValue(root->right, largeAns);
}
void inputData(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertBST(root, data);
        cin >> data;
    }
}

// assuming all values in tree must be unique
bool SerchTarget(Node *root, int target)
{

    // base case
    if (root == NULL)
    {
        return false;
    }

    if (target == root->data)
    {
        return true;
    }
    else if (target < root->data)
    {
        return SerchTarget(root->left, target);
    }
    else
    {
        return SerchTarget(root->right, target);
    }
}
Node *DeleteNode(Node *root, int target)
{

    // base case
    if (root == NULL)
    {
        return NULL;
    }

    if (target == root->data)
    {

        if (root->left == NULL && root->right == NULL)
        {
            // leaf node
            delete root;
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            // root->?left has chhild
            Node *child = root->left;
            delete root;
            return child;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            // root->?right has chhild
            Node *child = root->right;
            delete root;
            return child;
        }
        else
        {
            // rooot->left and root->right both have child
            // find root->left, max value
            cout << "root data is: " << root->data << endl;
            int max = largeValue(root->left);
            cout << "max value is: " << max << endl;
            root->data = max;
            // cout<<max<<endl;
            // return DeleteNode(root->left, max);//here i return the function not root
            // here if we have to return then it will return null
            // so, ne need to return here , we have handle it when root->left and
            // root->right will null then, root -> null and delte and here we return the null

            root->left = DeleteNode(root->left, max);
        }
    }
    else if (target < root->data)
    {
        root->left = DeleteNode(root->left, target);
    }
    else
    {
        root->right = DeleteNode(root->right, target);
    }
}
Node *inorderCreateBst(Node *&root, int inorder[], int s, int e)
{
    if (s > e)
        return NULL;
    int mid = s + (e - s) / 2;
    int nodeVal = inorder[mid];
    // cout<<"root data is:"<<nodeVal<<endl;
    root = new Node(nodeVal);
    // cout<<root->data<<endl;

    inorderCreateBst(root->left, inorder, s, mid - 1);
    inorderCreateBst(root->right, inorder, mid + 1, e);

    return root;
}
void insertDublyLinkedListInBst(Node *root, Node *&head)
{
    // base case
    if (root == NULL)
        return;
    // call-> right part utill not getting null
    insertDublyLinkedListInBst(root->right, head);

    // when back ->backtracking perform the DLL logic
    root->right = head;
    if (head != NULL)
        head->left = root;
    // updae head
    head = root;

    // also call the->left part
    insertDublyLinkedListInBst(root->left, head);
}
void printDLLInBst(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
}

Node *sortLinkedListInBst(Node *&head, int n)
{
    if (n <= 0 || head == NULL)
        return NULL;
    Node *leftSubtree = sortLinkedListInBst(head, n - 1 - n / 2);

    Node *root = head;
    root->left = leftSubtree;
    head = head->right;

    root->right = sortLinkedListInBst(head, n / 2);
    return root;
}

void root1Ans(Node *root1, vector<int> &ans1)
{
    if (root1 == NULL)
        return;
    root1Ans(root1->left, ans1);

    ans1.push_back(root1->data);

    root1Ans(root1->right, ans1);
}
void root2Ans(Node *root2, vector<int> &ans2)
{
    if (root2 == NULL)
        return;
    root1Ans(root2->left, ans2);

    ans2.push_back(root2->data);

    root1Ans(root2->right, ans2);
}
vector<int> mergeTwoArray(vector<int> &ans1, vector<int> &ans2)
{
    int sizeAns1 = ans1.size();
    int sizeAns2 = ans2.size();
    int i = 0, j = 0;
    vector<int> ans;

    while (i < sizeAns1 && j < sizeAns2)
    {
        if (ans1[i] < ans2[j])
        {
            ans.push_back(ans1[i]);
            i++;
        }
        else
        {
            ans.push_back(ans2[j]);
            j++;
        }
    }
    while (i < sizeAns1)
    {
        ans.push_back(ans1[i]);
        i++;
    }
    while (j < sizeAns2)
    {
        ans.push_back(ans2[j]);
        j++;
    }

    return ans;
}
vector<int> merge(Node *root1, Node *root2)
{

    // Your code here
    vector<int> ans1;

    vector<int> ans2;

    root1Ans(root1, ans1);

    root2Ans(root2, ans2);

    return mergeTwoArray(ans1, ans2);
}
void print(vector<int> &inorder)
{
    for(int i=0;i<inorder.size();i++)
    {
        cout<<inorder[i]<<" ";
    }
}


void TwoBstInSingleBst(Node* &root, vector<int> &inorder, int s, int e)
{
   if(s > e)
   {
    return;
   }

   int mid = s+(e-s)/2;
   int val = inorder[mid];

   root = new Node(val);

   TwoBstInSingleBst(root->left, inorder, s, mid-1);
   TwoBstInSingleBst(root->right, inorder, mid+1, e);
}
int main()
{
    /*
    Node *root = NULL;
    inputData(root);
    // 20 15 18 4 9 60 25 80 2 35 49 67 90  17 -1
    cout<<"Tree is: "<<endl;
    levelOrderTreversal(root);
    cout<<endl;
    // cout<<"InOrder Traversal is: "<<endl;
    // inOrderTraversal(root);
    // cout<<endl;
    // cout<<"PreOrder Traversal is: "<<endl;
    // PreOrderTraversal(root);
    // cout<<endl;
    // cout<<"PostOrder Traversal is: "<<endl;
    // PostOrderTraversal(root);
    // cout<<endl;
    // cout<<"Search Target: "<<SerchTarget(root, 180);

    // // int smallAns = 0;
    // // int largeAns = 0;
    // // smallValue(root, smallAns);
    // // largeValue(root, largeAns);
    // cout<<endl;
    // cout<<"Small value of Tree is: "<<smallValue(root);
    // cout<<endl;
    // cout<<"Larger value of Tree is: "<<largeValue(root);

    cout<<"After Delete Node the Tree is: "<<endl;
    DeleteNode(root, 15);
    levelOrderTreversal(root);
    */
    // Node *root = NULL;
    // //    int inorder[] = {1,2,3,4,5,6,7,8,9};
    // int inorder[] = {10, 30, 50, 60, 100, 150, 200, 250, 270, 300};
    // int s = 0;
    // int e = sizeof(inorder) / sizeof(int) - 1;
    // root = inorderCreateBst(root, inorder, s, e);
    // levelOrderTreversal(root);

    // Node *head = NULL;
    // cout << "Dubly Linked List in Bst: " << endl;
    // insertDublyLinkedListInBst(root, head);
    // printDLLInBst(head);

    // cout << endl;
    // cout << "Sorted Linked List in Bst: " << endl;
    // Node *root1 = sortLinkedListInBst(head, 10);

    // levelOrderTreversal(root1);
    //root1 = 5 2 4 6 -1
    //root2 = 1 3 7 -1
    Node* root1 = NULL;
    Node* root2 = NULL;
    cout<<"create Bst for root1: "<<endl;
    inputData(root1);

    cout<<"Tree is one:"<<endl;
    levelOrderTreversal(root1);
    cout<<endl;


  

    cout<<"create Bst for root2: "<<endl;
    inputData(root2);
    cout<<"Tree is two:"<<endl;
    levelOrderTreversal(root2);

    cout<<endl;
    vector<int> inorder =  merge(root1, root2);
    cout<<"print inoder merge two Bst: "<<endl;
    print(inorder);

    int s=0;
    int e= inorder.size()-1;

    Node* root = NULL;
    TwoBstInSingleBst(root,inorder, s, e);
    cout<<endl;
    cout<<"After megrge two Bst in single Bst is: "<<endl;
   
    levelOrderTreversal(root);

    return 0;
}