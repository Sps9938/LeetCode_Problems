#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        cout<<"DeConstructor is called:"<<this->data<<endl;
    }
};
void insertAtHead(Node *&head, Node *&tail, int data)
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
        newnode->next = head;
        head = newnode;
    }
}
void insertAtTail(Node *&head, Node *&tail, int data)
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
        tail->next = newnode;
        tail = newnode;
    }
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}
int printLength(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void deletionAtHead(Node *&head, Node *&tail)
{
    if (head != NULL)
    {
        Node *temp=head;
        head = temp->next;
        temp->next=NULL;
        delete temp;

    }
}

void deletionAttail(Node *&head, Node *&tail, int length)
{
    if (head != NULL)
    {
        // Node *curr = head;
        // Node *prev=NULL;
        // while (length != 1)
        // {
            
            
        //     // if (count == length - 1)
        //     // {
        //     //     tail = temp;
        //     //     tail->next = NULL;
        //     //     break;
        //     // }
        //     prev=curr;
        //     curr=curr->next;
        //     length--;
        // }
        // tail=prev;
        // tail->next=NULL;
        // // delete prev;
        // delete curr;

        //better approach
        Node *prev=head;
        while(prev->next != tail)
        {
            prev=prev->next;
        }
        prev->next=NULL;
        delete tail;
        tail=prev;
    }
}
void deleteAtposition(Node *&head, Node *&tail, int length, int position)
{
    if(head == tail)
    {
        Node *temp=head;
        delete temp;
        head=NULL;
        tail=NULL;

    }
    if (position < 1 || position > length)
    {
        cout << "Enter a valid Position" << endl;
    }
    if (position == 1)
    {
        cout << "Delete at head" << endl;
        deletionAtHead(head, tail);
        print(head);
    }
    if (position == length)
    {
        cout << "Delete at Tail" << endl;
        deletionAttail(head, tail, length);
        print(head);
    }
    else if (position > 1 && position < length)
    {
        cout << "Delete at Position" << endl;
        Node *prev = NULL;
        Node *curr = head;
        Node *temp = head;
        while (position != 1)
        {
            temp = temp->next;
            prev = curr;
            curr = curr->next;
            position--;
        }
        prev->next = curr->next;
        curr->next=NULL;
        delete curr;
        print(head);
    }
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtTail(head, tail, 10);
    // insertAtTail(head, tail, 20);
    // insertAtTail(head, tail, 30);
    // insertAtTail(head, tail, 40);
    // insertAtTail(head, tail, 50);
    // insertAtTail(head, tail, 60);
    // insertAtTail(head, tail, 70);
    print(head);
    cout << endl;
    // cout << tail << endl;
    int length = printLength(head);
    // deletionAtHead(head,tail);
    // cout << endl;
    // deletionAttail(head, tail, length);

    // cout << endl;
    // cout << tail;
    deleteAtposition(head, tail, length, 1);
    if(head ==NULL)
    {
        cout<<"Head is NULL"<<endl;
    }
    if(tail == NULL)
    {
        cout<<"Tail is NUll"<<endl;
    }
}