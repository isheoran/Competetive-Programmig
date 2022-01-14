#include<iostream>
using namespace std;

class node
{
    public:
    int data ;
    node* next;
    node(int value)
    {
        data = value;
        next = NULL;
    }
};

void Insert_at_tail(node * &head, int value)
{
    node* n = new node(value);
    if(head == NULL)
    {
        head = n;
        return;
    }
    node * temp = head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = n;
}

void create_cycle(node* &head)
{ 
    node * temp1,*temp2;
    temp2 = head;
    for(int i=1;temp2->next!=NULL;i++)
    {
        if(i==4) temp1=temp2;
        temp2=temp2->next;
    }
    temp2->next=temp1;
}

void remove_cycle(node* &head)
{
    node* temp1,*temp2;
    temp1=temp2=head;
    do
    {
        temp1=temp1->next;
        temp2=temp2->next->next;
    } while (temp1 != temp2);
    temp1 = head;
    //node loop stops when they encounter same node(obviously inside cycle)
    //again iterate each 1 step forward after taking temp1 at head to reach connection of cycle to parent chain
    while(temp1->next != temp2->next)
    {
        temp1=temp1->next;
        temp2=temp2->next;
    }
    temp2->next = NULL;
}

void print_list(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main()
{
    node* head = NULL;
    for(int i=0;i<20;i++) Insert_at_tail(head,i+1);
    //print_list(head);
    /*This list has 20 elements and lets join 20th link to positon 4th in this list
    to create a cycle of 17 elements in this list. */
    create_cycle(head);
    //print_list(head);
    //Lets say we don't know that there is cycle in this list (element 4 connected to element 20)
    //first we will detect this cycle and then remove that cycle
    //we will do this the help of floyd's algorithm 

    remove_cycle(head);
    print_list(head);
    return 0;
}