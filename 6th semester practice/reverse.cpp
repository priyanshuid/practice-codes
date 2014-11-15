#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <map>
#include <queue>
#include <vector>
#include <list>
#include <string.h>
using namespace std;
class node 
{
	public:
		int data;
		node *next;
};
void reverse(node **head)
{
	node *t1=NULL;
	node *t2=*head;
	node *t3;
	while(t2!=NULL)
	{
		t3=t2->next;
		t2->next=t1;
		t1=t2;
		t2=t3;
	}
	*head=t1;
}
int main()
{
	cout<<"NO. OF NODES";
	int n;
	cin>>n;
	node *head=NULL;
	node *temp=new node();
	node *temp1;
	for(int i=0;i<n;i++)
	{
		int v;
		cin>>v;
		if(head== NULL)
			{
				head=new node();
				head->data=v;
				head->next=NULL;
				temp=head;
			}
		else
		{
			temp1=new node();
			temp1->data=v;
			temp1->next=NULL;
			temp->next=temp1;
			temp=temp1;
			
		}
	}
	reverse(&head);
	cout<<"reversed list"<<endl;
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	return 0;
}

