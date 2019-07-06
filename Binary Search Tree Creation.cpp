#include<bits/stdc++.h>
using namespace std;
struct Node
{
   int data;
   Node *left;
   Node *right;
}*root = NULL;
Node *createNode(int data)
{
    Node *p = new Node();
    p->data = data;
    p->left = p->right = NULL;
    return p;
}
Node *insert(Node *root,int data)
{
    if(root==NULL)
    {
        root = createNode(data);
        return root;
    }
    else
    {
        if(root->data<data)
        {
            root->right = insert(root->right,data);
        }
        else
        {
            root->left = insert(root->left,data);
        }
    }
    return root;
}
void preorder(Node *root)
{
    if(root)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    Node *root = NULL;
    root = insert(root,5);
    insert(root,2);
    insert(root,7);
    insert(root,1);
    insert(root,3);
    insert(root,6);
    insert(root,8);
    preorder(root);
}
