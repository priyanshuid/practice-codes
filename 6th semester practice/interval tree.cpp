//RMQ
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
int buildTree(int ar[],int segTree[],int start,int end,int index)
{
	if(start==end)
	{
		 segTree[index]=ar[start];
		 return segTree[index];
	}
	else
	{
		int mid=start+ (end-start)/2;
		segTree[index]= max(buildTree(ar, segTree , start, mid, 2*index+1),buildTree ( ar, segTree, mid+1 , end, 2*index+2));
		return segTree[index];
	}
}
int query(int segTree[], int start, int end, int l, int r, int index)
{
	if(r< start || l > end )
		return 0;
	else if( l<=start  && r>=end)
		return segTree[index];
	else
	{
		mid=st+ (en-st)/2;
		return max(query(segTree , start, mid , l , r , 2*index+1),query(segTree, mid+1, end, l, r, 2*index+2)); 
	}
}
int update(int segTree[],int start, int end , int update_pos , int index)
{
	if()
}
int main()
{
	int n;
	cin>>n;
	int ar[n];
	int segTree[(2.5)*n];
	for(int i=0;i<n;i++)
		cin>>ar[i];
	int rand=buildTree(ar,segTree,0,n,0);
	cout<<" NO. OF Queries :";
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		char a;
		cin>>a;
		if(a==' U ')
		{
			cout<<"Index Of Update:";
			int iUpdate;
			cin>>iUpdate;
			updateTree(segTree,0,N,iUpdate,0);
		}
		else if(a== ' Q ' )
		{
			cout<<"Left:";
			int l;
			cin>>l;
			cout<< "Right:";
			int r;
			cin>>r;
			cout<< " Queried Sum:" <<queryTree(segTree,0,N,l,r,0)<<endl;
		}
	}
	return 0;
}

