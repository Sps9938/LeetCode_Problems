#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *Build()
{
    cout << "Enter the data" << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    // cout<<"Enter the data for inserting left for root->"<<data<<endl;
    // root->left = Build(root->left);
    // cout<<"Enter the data for inseting right for root->"<<data<<endl;
    Node *root = new Node(data);
    cout << "Enter the data for inserting left for root->" << data << endl;
    root->left = Build();
    cout << "Enter the data for inseting right for root->" << data << endl;
    root->right = Build();
    return root;
}
void preOrderTraversal(Node *root)
{
    // step 1: Root
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    // step 2: Left
    preOrderTraversal(root->left);
    // step 3: Right
    preOrderTraversal(root->right);
}
void InOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    // step 1: left
    InOrderTraversal(root->left);

    // step 2: Root
    cout << root->data << " ";
    // step 3: Right
    InOrderTraversal(root->right);
}
void postOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    // step 1: left
    postOrderTraversal(root->left);
    // step 2: Right
    postOrderTraversal(root->right);
    // step 3: Node
    cout << root->data << " ";
}
void levelorderTraversal(Node *root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node *front = q.front();
        cout<<front->data<<" ";
        q.pop();

        if(front->left != NULL)
        {
            q.push(front->left);
        }
        if(front->right != NULL)
        {
            q.push(front->right);
        }
    }
}

void levelWisePrint(Node *root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if(front == NULL)
        {
            cout<<endl;
            // q.push(NULL);
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout<<front->data<<" ";
            if(front->left != NULL)
            {
                q.push(front->left);
            }  
            if(front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}
int main()
{
    Node *root = Build();
    // root = Build(root);
    // //5 8 11 -1 -1 12 -1 -1 9 4 -1 -1 6 -1 -1
    // 10 20 40 80 -1 -1 90 -1 -1 50 -1 -1 30 60 -1 -1 70 110 -1 -1 120 -1 -1
    cout<<"Enter the value of Node"<<endl;
    cout << "Preorder Traversal" << endl;
    preOrderTraversal(root);
    cout << endl;
    cout << "Inorder Traversal" << endl;
    InOrderTraversal(root);
    cout<<endl;
    cout << "postorder Traversal" << endl;
    postOrderTraversal(root);
    cout << endl;
    cout<<endl;
    cout << "levelOrder Traversal" << endl;
    levelorderTraversal(root);
    cout << endl;
    cout << "levelWisePrint Traversal" << endl;
    levelWisePrint(root);
    cout << endl;

    // cout<<root->data;
    return 0;
}