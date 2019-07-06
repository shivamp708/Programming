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


//Insertion

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


//Display
void Display(Node *head)
{
    Node *temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
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
}
