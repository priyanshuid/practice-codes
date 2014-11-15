#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <map>
typedef struct node node;
#define unsigned long long ull
using namespace std;
struct node
{
	int val;
	node *next;
	node *previous;
	node()
	{
		val=0;
		next=NULL;
		previous=NULL;
	}
	node(int a)
	{
		val=a;
		next=NULL;
		previous=NULL;
	}
};
node *create()
{
	node *HEAD;
	HEAD=new node();
	HEAD->next=NULL;
	HEAD->previous=NULL;
	return HEAD;
}
node* add(int val,node *PTR)
{
	node *temp=new node(val);
	temp->next=NULL;
	PTR->next=temp;
	temp->previous=PTR;
	return temp;
}
void print_fwd(node *HEAD)
{
	cout<<"HEAD->";
	node *ptr=HEAD->next;
	while(ptr!=NULL)
	{
		cout<<ptr->val<<"->";
		ptr=ptr->next;
	}
	cout<<"TAIL";
}
void print_bkd(node *TAIL)
{
	cout<<"TAIL<-";
	node *ptr=TAIL;
	while(ptr->previous!=NULL)
	{
		cout<<ptr->val<<"<-";
		ptr=ptr->previous;
	}
	cout<<"HEAD";
}
int main()
{
	node *HEAD,*TAIL;
	HEAD=create();
	cout<<"HOW MANY VALUES TO ENTER:";
	int k;
	cin>>k;
	cout<<"INSERT ELEMENTS\n";
	for(int i=0;i<k;i++)
	{
		int val;
		cout<<i+1<<":";
		scanf("%d",&val);
		if(i==0)
			TAIL=add(val,HEAD);
		else
			TAIL=add(val,TAIL);
	}
	cout<<"List Printed Forward:"<<endl;
	print_fwd(HEAD);
	cout<<endl;
	cout<<"List Printed Backward:"<<endl;
	print_bkd(TAIL);
	cout<<endl;
	return 0;
}	
	

