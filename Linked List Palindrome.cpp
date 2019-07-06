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


void Display(Node *head)
{
    Node *temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

bool palindrome(Node *head)
{
    /*
    1.The main idea is to reverse the second half of linked list then check 
    if it is a palindrome or not.
    2.Consider the case of even length palindrome and odd length palindrom.
    
    
    for this...
      1.first find the length
      2.find the mid point
      3.find pointer at mid
      4.reverse second half
      5.traverse from start and mid+1(according to the length) position
      6.check if all the node have same value then it is a pailndrome else
      not a palindrome.
    */
    
    if(head==NULL)
    {
        return true;
    }
    Node *p = head;
    int count = 0;
    while(p)
    {
        count+=1;
        p = p->next;
    }
    int mid = (count+1)/2;
    int temp = 0;
    p = head;
    while(temp<mid-1)
    {
        p =p->next;
        temp+=1;
    }
    //cout<<p->data<<" ";
    Node *curr = p->next,*prev = NULL,*Next = NULL;
    while(curr)
    {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    p->next = prev;
    Node *q = head;
    Node *tr = head;
    temp = 0;
    while(temp<mid-1)
    {
        tr =tr->next;
        temp+=1;
    }
    tr = tr->next;
    cout<<"\n";
    Display(head);
    cout<<"\n";
    if(count%2==0)
    {
        int i = 0;
        while(i<mid)
        {
            cout<<"q->"<<q->data<<" tr->"<<tr->data<<"\n";
            if(q->data!=tr->data)
            {
                
                return false;
            }
            q = q->next;
            tr = tr->next;
            i+=1;
        }
        return true;
    }
    else
    {
        int j = 0;
        while(j<mid-1)
        {
            cout<<"q->"<<q->data<<" tr->"<<tr->data<<"\n";
            if(q->data!=tr->data)
            {
                return false;
            }
            q = q->next;
            tr = tr->next;
            j+=1;
        }
        return true;
    }
}



int main()
{
    Node *head = NULL;
    head = insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,3);
    insert(head,2);
    insert(head,5);
    Display(head);
    cout<<"\n";
    bool c = palindrome(head);
    if(c)cout<<"palindrome\n";else cout<<"Not a palindrome\n";
    Display(head);
    cout<<"\n";
}
