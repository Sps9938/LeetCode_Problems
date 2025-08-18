#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next = NULL;

    Node()
    {
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void print(Node *head, Node *tail)
{
    Node *temp = head;
    while (true)
    {
        if (temp == tail)
        {
            cout << temp->data;
            break;
        }
        cout << temp->data << "->";
        temp = temp->next;
    }
}
int printLength(Node *head, Node *tail)
{
    Node *temp = head;
    int length = 0;
    while (true)
    {
        length++;
        if (temp == tail)
        {
            break;
        }
        temp = temp->next;
    }
    return length;
}
void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *newnode = new Node(data);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
        tail->next = head;
    }
}
void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newnode = new Node(data);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
        newnode->next = head;
    }
}

void insertAtPostion(Node *&head, Node *&tail, int data, int position, int length)
{
    if (position < 1)
    {
        cout << "Enter a valid position" << endl;
    }
    else if (position == 1)
    {
        cout << "Insert at Head" << endl;
        insertAtHead(head, tail, data);
        print(head, tail);
    }
    else if (position >= length + 1)
    {
        cout << "Insert at Tail" << endl;
        insertAtTail(head, tail, data);
        print(head, tail);
    }
    else
    {
        cout << "Insert at any position" << endl;
        Node *newnode = new Node(data);
        Node *pr = NULL;
        Node *cur = head;
        while (position != 1)
        {
            pr = cur;
            cur = cur->next;
            position--;
        }
        pr->next = newnode;
        newnode->next = cur;
    }
}

void deleteAtposition(Node *&head, Node *&tail, int position)
{
    int length = printLength(head, tail);
    if (position < 1 || position > length)
    {
        cout << "Enter a valid Position" << endl;
    }
    if (head == NULL)
    {
        cout << "Linked list has not creatied Please Create Linked List" << endl;
        return;
    }
    if (head == tail)
    {

        cout << "Single element has handled and delete the node" << endl;
        Node *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
    }
    else
    {
        if (position == 1)
        {
            cout << "Delete at head" << endl;

            Node *temp = head;
            head = head->next;
            tail->next = head;
            temp = NULL;
            delete temp;
        }
        if (position == length)
        {
            cout << "Dlete at position tail" << endl;
            Node *prev = NULL;
            Node *curr = head;
            while (position != 1)
            {
                prev = curr;
                curr = curr->next;
                position--;
            }
            curr->next = NULL;
            prev->next = head;
            tail = prev;
            delete curr;
        }
        else if (position > 1 && position < length)
        {
            cout << "Delete at any position" << endl;
            Node *prev = NULL;
            Node *curr = head;
            while (position != 1)
            {
                prev = curr;
                curr = curr->next;
                position--;
            }
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);

    print(head,tail);

    // insertAtHead(head, tail, 70);
    // insertAtHead(head, tail, 100);
    /*
    int length = printLength(head,tail);

    cout<<endl;
    // insertAtPostion(head, tail, prev, next, 90, 6, length);
    cout<<"The Length of the Circular Linked lisst is: "<<printLength(head,tail);
    cout<<endl;
    print(head,tail);

    cout<<endl;
    int length = printLength(head, tail);
    insertAtPostion(head, tail, 800,3, length);
    cout<<endl;
    print(head,tail);

    */

    // cout << "The circurlar liked list is: " << endl;
    // ;
    // print(head, tail);

    // cout << endl;
    // deleteAtposition(head, tail, 1);
    // cout << endl;
    // print(head, tail);

    // cout << endl;
    // deleteAtposition(head, tail, 6);
    // cout << endl;
    // print(head, tail);

    // cout << endl;
    // deleteAtposition(head, tail, 1);
    // cout << endl;
    // print(head, tail);

    // cout << endl;
    // deleteAtposition(head, tail, 4);
    // cout << endl;
    // print(head, tail);

    // cout << endl;
    // deleteAtposition(head, tail, 2);
    // cout << endl;
    // print(head, tail);

    // cout << endl;
    // deleteAtposition(head, tail, 1);
    // cout << endl;
    // print(head, tail);

    // cout << endl;
    // deleteAtposition(head, tail, 1);
    // cout << endl;
    // print(head, tail);

    return 0;
}