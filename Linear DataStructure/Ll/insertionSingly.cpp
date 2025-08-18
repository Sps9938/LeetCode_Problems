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
    Node(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
    }
};
int printLength(Node *head)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp=temp->next;
    }
    return length;
}
void insertAtHead(Node *&head,Node *&tail,int data)//if you not passed reference after the function end update of head destoryed
//and reamin same
{
    //handle empyy linked list
    if(head == NULL)
    {
        //step1:create a newnode
        Node *newnode=new Node(data);
        //step2:head=newnode
        head=newnode;
        tail=newnode;
    }
    else{
        Node *newnode=new Node(data);
        newnode->next=head;
        head=newnode;
    }

}
void insertAtTail(Node *&head,Node *&tail,int data)//if you not passed reference after the function end update of head destoryed
//and reamin same
{
    //handle empyy linked list
    if(head == NULL)
    {
        //step1:create a newnode
        Node *newnode=new Node(data);
        //step2:head=newnode
        tail=newnode;
        head=newnode;
  
    }
    else{
        Node *newnode=new Node(data);
        tail->next=newnode;
        tail=newnode;
    }
  

}
  void insertAtPostition(Node *&head,Node *&tail,int data,int position,int length)
    
    {
        if(position < 1)
        {
            cout<<"Insert at valid position"<<endl;
        }
        if(position ==  1)
        {
            cout<<"Insert At head"<<endl;
            insertAtHead(head,tail,data);
        }
        else if(position > length)
        {
            cout<<"Insert At tail"<<endl;
            insertAtTail(head,tail,data);
        }
        else
        {
            cout<<"Insert At position"<<endl;
            Node *newnode=new Node(data);
            Node *prevnode=NULL;
            Node *currnode=head;
            while(position != 1)
            {
                prevnode=currnode;
                currnode=currnode->next;
                position--;
            }
            newnode->next=currnode;
            prevnode->next=newnode;
        }
    }
int main()
{
    // Node *first = new Node(10);
    // Node *second = new Node(20);
    // Node *third = new Node(30);
    // Node *fourth = new Node(40);
    // Node *fifth = new Node(50);
    // Node *head=first;
    // Node *tail=fifth;
    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;

    // Node *head = new Node(first);
   
    // cout << "print length of linked list: ";
    
    // insertAtHead(head,tail,5);
    Node *head=NULL;
    Node *tail=NULL;
    insertAtTail(head,tail,10);
    insertAtTail(head,tail,20);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,40);
    insertAtTail(head,tail,50);
    insertAtTail(head,tail,60);
    insertAtTail(head,tail,70);
    int length=printLength(head);
    Node *hea = new Node(head);
    cout<<endl;
    insertAtPostition(head,tail,600,7,length);
    Node *he = new Node(head);
    return 0;
}