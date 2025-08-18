#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev = NULL;
    Node *next = NULL;
    Node()
    {
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}
void insertAtHead(Node *&head, Node *&tail, Node *&prev, Node *&next, int data)
{
    if (head == NULL)
    {
        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
    }
    else
    {
        Node *newnode = new Node(data);
        next = head;
        newnode->prev = NULL;
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}
void insertAtTail(Node *&head, Node *&tail, Node *&prev, Node *&next, int data)
{
    if (head == NULL)
    {
        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
    }
    else
    {
        // create newnode
        Node *newnode = new Node(data);
        tail->next = newnode;
        newnode->prev = tail;
        newnode->next = NULL;
        tail = newnode;
    }
}
void insertAtPostion(Node *&head, Node *&tail, Node *&prev, Node *&next, int data, int position, int length)
{
    if (position < 1)
    {
        cout << "Enter a valid position" << endl;
    }
    if (position == 1)
    {
        cout << "Insert at Head" << endl;
        insertAtHead(head, tail, prev, next, data);
        print(head);
    }
    if (position >= length + 1)
    {
        cout << "Insert at Tail" << endl;
        insertAtTail(head, tail, prev, next, data);
        print(head);
    }
    else
    {
        // cout << "Insert at position" << endl;
        Node *newnode = new Node(data);
        Node *temp = head;
        Node *pr = NULL;
        Node *cu = head;
        while (position != 1)
        {
            position--;
            pr = cu;
            cu = cu->next;
        }
        newnode->prev = pr;
        pr->next = newnode;
        newnode->next = cu;
        cu->prev = newnode;
        print(head);
    }
}

int printLength(Node *head)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    Node *prev = NULL;
    Node *next = NULL;
    insertAtTail(head, tail, prev, next, 10);
    insertAtTail(head, tail, prev, next, 20);
    insertAtTail(head, tail, prev, next, 30);
    insertAtTail(head, tail, prev, next, 40);
    insertAtTail(head, tail, prev, next, 50);
    int length = printLength(head);
    insertAtPostion(head, tail, prev, next, 90, 6, length);

    // print(head);
}