#include<iostream>
using namespace std;
class Node {
    public:
        int data;
        Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void insertAtHead(Node* &head,Node* &tail,int data)
{
    //handle haad
    Node *newnode = new Node(data);
   
    if(head == NULL)
    { 
        head = newnode;
        tail = newnode;
    }
    else{
       newnode->next = head;
       head = newnode;


    }
}
void insertAtTail(Node* &head,Node* &tail,int data)
{
    //handle haad
    Node *newnode = new Node(data);
   
    if(tail == NULL)
    { 
        tail = newnode;
        head = newnode;
    }
    else{
       tail->next = newnode;
       tail = newnode;


    }
}
void print(Node *&head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int length(Node *head)
{
    Node* temp = head;
    int length=0;
    while(temp!=NULL)
    {
        length++;
        temp=temp->next;
    }
    return length;
}
void insertAtAnyPostion(Node* &head, Node* &tail,int data, int length, int position)
{
    if(position < 1)
        cout<<"Enterd Invlid postion"<<endl;
    else if(position == 1)
    {
        cout<<"Insert at Head"<<endl;
        insertAtHead(head, tail, data);
    }
    else if(position > length)
    {
        cout<<"Insert at Tail"<<endl;
        insertAtTail(head,tail, data);
    }
    else{
        cout<<"Insert at any position"<<endl;
        Node *newnode = new Node(data);
        Node *prev = NULL;
        Node *curr = head;
        while(position != 1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }
        newnode->next = curr;
        prev->next = newnode;
        
    }
}
void deleteAtHead(Node *&head, Node *&tail)
{
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;

}
void deleteAtTail(Node *&head, Node *&tail)
{
    Node *prev = NULL;
    Node *curr = head;
    while(curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    tail = curr;
    delete curr;
}
void deleteAtAnyPostion(Node* &head, Node* &tail,int length, int position)
{
    // cout<<position<<" "<<length<<endl;
    if(position < 1 || position > length)
    {
        cout<<"Enter a valid position"<<endl;
    }
    else if(position == 1)
    {
        cout<<"Delete at head"<<endl;
        deleteAtHead(head,tail);
    }
    else if(position == length)
    {
        cout<<"Delete at tail"<<endl;
        deleteAtTail(head, tail);
       
    }
    else{
        cout<<"Delete at any position"<<endl;
        Node *prev = NULL;
        Node *curr = head;
        while(position != 1)
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
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    // insertAtHead(head,tail,10);
    // insertAtHead(head,tail,20);
    // insertAtHead(head,tail,30);
    insertAtHead(head,tail,900);
    insertAtTail(head,tail,100);
    insertAtTail(head,tail,20);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,40);

    int l = length(head);

    insertAtAnyPostion(head, tail, 700, l,7);
    insertAtAnyPostion(head, tail, 500, l,4);

    int nl = length(head);

    cout<<"After Inserting The LinkdeLIst is: "<<endl;
    
    print(head);
    cout<<endl;
    cout<<"After Deleting  The LinkdeLIst is: "<<endl;
    deleteAtAnyPostion(head, tail, nl, 1);
    cout<<endl;
    print(head);

    // cout<<"length of ll is: "<<length(head);
}