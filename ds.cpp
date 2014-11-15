#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <fstream>
#typedef struct node node
struct node
{
	int left_weight;
	int self_weight;
	int right_weight;
	node *parent;	
	vector <*node> left;
	vector <*node> right;
};
int solve(
int main()
{
	string input,output;
	cin>>input>>output;
	ifstream in.open(input);
	ofstream out.open(output);	
	int t;
	in>>t;
	for(int t1=0;t1<t;t1++)
	{
		int n;
		in>>n;
		node *root;
		for(int i=0;i<n;i++)
		{
			if(i==0)
			{				
				root=new node;
				root->key=i;				
				root->self_weight=10;			
				int m;
				in>>m;
				root->left_weight=m;
				int val;
				while(scanf("%d",&val))					
				{	
					node *n1=new node;
					n1->key=val;					
					root->left.push_back(n1);
				}	
				int k;
				in>>k;
				root->right_weight=k;
				while(scanf("%d",&val))
				{
					node *n2=new node;
					n2->key=val;					
					root->right.push_back(val);
				}
			else
			{
				int j;				
				for(j=0;j<root->left.size();j++)
				{	
					
					if(i==root->left[j]->val)
					
	}
				
	}
}
	
	
}
