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
struct node
{
	int v;
	double val;
	node *left;
	node *right;
	node *parent;
};
void put(node *root,bool lr,int number,double p)
{
	node *n=new node;
	n->left=NULL;
	n->right=NULL;
	n->v= number;
	n->val=p;
	n->parent=root;
	if(lr==0)
		root->left=n;
	else
		root->right=n;	
}
void insert(node *root ,int number1, int number2,double p)
{
		if(root->v!=number1 && root->v!=number2)
		{
			if(root->left==NULL && root->right==NULL)
			 	{
			 		put(root,0,number1,p);
			 		put(root,1,number2,1-p);
			 		return;
			 	}
		}
		else if(root->v!=number1)
		{
			if(root->left==NULL && root->right->v!=number1)
			{
				put(root,0,number1,p);
				return;
			}
			else
				insert(root->left,number1,number2,p);
			
			if(root->right==NULL && root->left->v!=number1)
			{
				put(root,1,number1,p);
				return;
			}
			else
				insert(root->right,number1,number2,p);
		}
		else if(root->v!=number2)
		{
			if(root->left==NULL && (root->right==NULL && root->right->v!=number2))
			{
				put(root,0,number2,p);
				return;
			}
			else
				insert(root->left,number1,number2,p);
			if(root->right==NULL && root->left->v!=number2)
			{
				put(root,1,number2,1-p);
				return;
			}
			else
				insert(root->right,number1,number2,p);
		}
}
void inorder(node *root)
{

	if(root->left!=NULL)
		inorder(root->left);
		cout<<root->v<<" ";
	if(root->right!=NULL)
		inorder(root->right);	
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int t1=0;t1<t;t1++)
	{
		int n;
		scanf("%d",&n);
		double a[n],b[n];
		node *root=new node;
		root->left=NULL;   root->right=NULL;    root->parent=NULL;    root->val=1;   root->v=0;
		for(int i=0;i<n;i++)
		{
			int a1,b1,p1;
			scanf("%d%d%d",&p1,&a1,&b1);
			insert(root,a1,b1,p1/100);	
		}
		inorder(root);
		cout<<endl;
	}
}
