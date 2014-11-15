/* Program To create a binary search tree (BST)  out of the nodes given as the input from the user 
Draw a menu based query which have options to choose to 
1: Return parent 
2: Return Child 
3: Traverse the tree in Inorder
4: Traverse the tree in Preorder
5: Traverse the tree in Postorder
6: Print the root node
7: Check if the node is a leaf node
8: Find Value Succcessor*/ 
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <math.h>
#include <map>
#define unsigned long long ull
using namespace std;
struct tnode
{
	int val;
	tnode *left;
	tnode  *right;
	tnode *parent;
	tnode(int v)
	{
		val=v;
		left=NULL;
		right=NULL;
		parent=NULL;
	}
};
tnode *create(int val);
void insert(tnode *root,int val);
tnode *find(tnode *root,int val);
tnode *parent(tnode * child);
tnode *left_child(tnode *prnt);
tnode *right_child(tnode *prnt);
void pre_order(tnode *root);
void in_order(tnode *root);
void post_order(tnode *root);
int val(tnode *pos);
bool isLeaf(tnode *node);
tnode *leftmost(tnode *node);
tnode *succesor(int val);
int main()
{
	cout<<"Enter the no. of entries:";
	int n;
	cin>>n;
	tnode *root;
	for(int i=0;i<n;i++)
	{
		int t;
		scanf("%d",&t);
		if(i==0)
			root=create(t);
		else
			insert(root,t);
	}
	int qry;
	bool flag=false;
	do{
		cout<<"Continue?";
		char ch;
		cout<<"\nN:NO\nY:YES\n";
		cin>>ch;
		if(ch=='N')
			break;
		cout<<"1:Return Parent\n2:Return Child\n3:Pre-order Traversal\n4:In-order Traversal\n5:Post-Order\n6:Print Root Node\n7:Check for Being Leaf\n";
		cin>>qry;
		switch(qry)
		{
			case 1:
				{
					cout<<"Enter the node whose parent has to be found:";
					int tmp;
					cin>>tmp;
					tnode *chld=find(root,tmp);
					if (chld==root)
						cout<<"NODE NOT FOUND IN THE TREE"<<endl;
					else
					{
						tnode *prnt=parent(chld);
						int val1=val(prnt);
						cout<<"Parent of the given child:"<<val1<<endl;
					}
					break;
					
				}
			case 2:
				{
					cout<<"Enter the node whose child has to be found:";
					int tmp;
					cin>>tmp;
					tnode *prnt=find(root,tmp);
					if(prnt==NULL)
						cout<<"NODE NOT FOUND IN THE TREE"<<endl;
					else
					{
						tnode *lft_child=left_child(prnt);
						tnode *rght_child=right_child(prnt);
						int l_val=val(lft_child);
						int r_val=val(rght_child);
						cout<<"Left Child:"<<l_val<<endl<<"Right Child:"<<r_val<<endl;
					}
					break;
				}
			case 3:
				{
					cout<<"Pre Order Traversal"<<endl;
					tnode *tmp=root;
					pre_order(tmp);
					cout<<endl;
					break;
				}
			case 4:
				{
					cout<<"In-order Traversal"<<endl;
					tnode *tmp=root;
					in_order(tmp);
					cout<<endl;
					break;
				}
			case 5:
				{
					cout<<"Post-Order Traversal"<<endl;
					tnode *tmp=root;
					post_order(tmp);
					cout<<endl;
					break;
				}
			case 6:
				{
					cout<<"Root Node is:"<<val(root)<<endl;
					break;
				}
			case 7:
				{
					cout<<"Enter the node to be checked:";
					int n;
					cin>>n;
					tnode *tmp=find(root,n);
					if(isLeaf(tmp)==true)
						cout<<"Node is a Leaf Node"<<endl;
					else 
						cout<<"Not a Leaf Node"<<endl;
					break;
				}
			default:
				{
					cout<<"Yo! Wrong Choice Man."<<endl;
					break;
				}
		}
	}while(flag!=true);
	
}
tnode *create(int val)
{
	tnode *root=new tnode(val);
	root->left=NULL;
	root->right=NULL;
	root->parent=NULL;
	return root;
}
int val(tnode *temp)
{
	return temp->val;
}
void insert(tnode *root,int value)
{
	if(value>val(root) && root->right==NULL)
	{
		tnode *temp=new tnode(value);
		temp->parent=root;
		temp->left=NULL;
		temp->right=NULL;
		root->right=temp;
	}
	else if(value<val(root) && root->left==NULL)
	{
		tnode *temp=new tnode(value);
		temp->parent=root;
		temp->left=NULL;
		temp->right=NULL;
		root->left=temp;
	}
	else if(value>val(root) && root->right!=NULL)
		insert(root->right,value);
	else if(value<val(root) && root->left!=NULL)
		insert(root->left,value);
}
tnode *find(tnode *root,int value)
{
	if(val(root)==value)
		return root;
	else if(val(root)<value && root->right!=NULL)
		return find(root->right,value);
	else if(val(root)>value && root->left!=NULL)
		return find(root->left,value);
	else return NULL;
}
tnode *parent(tnode *child)
{
	if(child->parent!=NULL)
		return child->parent;
	else return NULL;
}
tnode *right_child(tnode *parent)
{
	if(parent->right!=NULL)
		return parent->right;
	else
		return NULL;
}
tnode *left_child(tnode *parent)
{
	if(parent->left!=NULL)
		return parent->left;
	else 
		return NULL;
}
void pre_order(tnode *root)
{
	cout<<val(root)<<"->";
	if(root->left!=NULL)
		pre_order(root->left);
	if(root->right!=NULL)
		pre_order(root->right);
}
void in_order(tnode *root)
{
	if(root->left!=NULL)
		in_order(root->left);
		cout<<val(root)<<"->";
	if(root->right!=NULL)
		in_order(root->right);	
}	
void post_order(tnode *root)
{
	if(root->left!=NULL)
		post_order(root->left);
	if(root->right!=NULL)
		post_order(root->right);
		cout<<val(root)<<"->";
}
bool isLeaf(tnode *node)
{
	if(node->left==NULL && node->right==NULL)
		return true;
	else
		return false;
}
