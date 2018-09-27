#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *left,*right;
} *root = NULL;
void insert(int data)
{
	node *newnode = new node;
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	if(root == NULL)
	{
		root = newnode;
	}
	else
	{
		node *curr = root,*prev;
		while(curr!=NULL)
		{
			prev = curr;
			if(curr->data>data)
			{
				curr = curr->left;
			}
			else
			{
				curr=curr->right;
			}
		}
		if(prev->data>data)
		{
			prev->left = newnode;
		}
		else
		{
			prev->right = newnode;
		}
	}
}
void inorderTraversal(node *noode)
{
	if(noode)
	{
		if(noode->left) inorderTraversal(noode->left);
		cout<<noode->data<<" ";
		if(noode->right) inorderTraversal(noode->right);
	}
}
void preorderTraversal(node *noode)
{
	if(noode)
	{
		cout<<noode->data<<" ";
		if(noode->left) preorderTraversal(noode->left);
		if(noode->right) preorderTraversal(noode->right);
	}
}
void postorderTraversal(node *noode)
{
	if(noode)
	{
		if(noode->left) postorderTraversal(noode->left);
		if(noode->right) postorderTraversal(noode->right);
		cout<<noode->data<<" ";
	}
}
void allLeafNodesLeftToRight(node *rooot)
{
	if(rooot)
	{
		allLeafNodesLeftToRight(rooot->left);
		if(rooot->left==NULL && rooot->right==NULL) cout<<rooot->data<<" ";	
		allLeafNodesLeftToRight(rooot->right);
	}
}
void allLeafNodesRightToLeft(node *rooot)
{
	if(rooot)
	{
		allLeafNodesRightToLeft(rooot->right);	
		if(rooot->left==NULL && rooot->right==NULL) cout<<rooot->data<<" ";
		allLeafNodesRightToLeft(rooot->left);	
	}
}
void helper1(node *rooot)
{
	if(rooot->left)
	{
		cout<<rooot->data<<" ";
		helper1(rooot->left);
	}
}
void helper2(node *rooot)
{
	if(rooot->right)
	{
		helper2(rooot->right);
		cout<<rooot->data<<" ";
	}
}
void antiClockWiseBoundryTraversal(node *rooot)
{
		helper1(rooot);allLeafNodesLeftToRight(rooot);helper2(rooot);
}
void helper3(node *rooot)
{
	if(rooot->right)
	{
		cout<<rooot->data<<" ";
		helper3(rooot->right);
	}
}
void helper4(node *rooot)
{
	if(rooot->left)
	{
		helper4(rooot->left);
		cout<<rooot->data<<" ";
	}
}
void clockWiseBoundryTraversal(node *rooot)
{
	helper3(rooot);allLeafNodesRightToLeft(rooot);helper4(rooot);
}
int main()
{
	insert(50);
	insert(40);
	insert(20);
	insert(11);
	insert(69);
	insert(8);
	insert(12);
	insert(44);
	insert(78);
	insert(43);
	insert(45);
	insert(70);
	insert(80);
	cout<<"Inorder   :";inorderTraversal(root);cout<<endl;
	cout<<"Preorder  :";preorderTraversal(root);cout<<endl;
	cout<<"Postorder :";postorderTraversal(root);cout<<endl;
	cout<<"All leaf Nodes Left to Right:";allLeafNodesLeftToRight(root);cout<<endl;
	cout<<"All leaf Nodes Right to Left:";allLeafNodesRightToLeft(root);cout<<endl;
	cout<<"Anti clockwise Boundry Traversal:";antiClockWiseBoundryTraversal(root);cout<<endl;
	cout<<"Clockwise Booundry Traversal:";clockWiseBoundryTraversal(root);
}
