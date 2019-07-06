#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
}*tail = NULL;
Node *createNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}
Node *insert(Node *head,int data)
{
    if(head==NULL)
    {
        head = createNode(data);
        tail = head;
        return head;
    }
    else
    {
        tail-> next = createNode(data);
        tail = tail->next;
    }
}
Node *Reverse(Node *head)
{
    if(head==NULL)
    {
        return head;
    }
    Node *Curr = head,*Next = NULL,*Prev = NULL;
    while(Curr)
    {
        Next = Curr->next;
        Curr->next = Prev;
        Prev = Curr;
        Curr = Next;
    }
    head = Prev;
    return head;
}

void Display(Node *head)
{
    Node *temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}


//reverse the ll from the half
Node *ReverseHalf(Node *head)
{
    if(head==NULL)
    {
        return head;
    }
    int count = 0;
    Node *temp = head;
    while(temp)
    {
        temp = temp->next;
        count+=1;
    }
    int mid = count/2;
    cout<<count<<" "<<mid<<"\n";
    count = 1;
    temp = head;
    
    while(count<mid)
    {
        temp = temp->next;
        count+=1;
    }
    Node *temp2 = Reverse(temp->next);
    temp->next = temp2;
    return head;
}


int main()
{
    Node *head = NULL;
    head = insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    insert(head,7);
    Display(head);
    cout<<"\n";
    //head = Reverse(head);
    //Display(head);
    //cout<<"\n";
    head = ReverseHalf(head);
    Display(head);
    cout<<"\n";
    
}
