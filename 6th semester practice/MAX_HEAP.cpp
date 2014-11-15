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
bool hasLeft(int i,int heap_size)
{
	if(2*i<=heap_size)
		return true;
		return false;
}
bool hasRight(int i,int heap_size)
{
	if(2*i+1<=heap_size)
		return true;
		return false;
}
void max_heapify(int ar[],int heap_size,int i)
{
	if(hasLeft(i,heap_size) && hasRight(i,heap_size))
	{
		int largest=i;
		int right=2*i+1,left=2*i;
		if(ar[right]>largest)
			largest=right;
		else if(ar[left]>largest)
			largest=left;
		if(largest!=i)
		{
				int temp=ar[largest];
				ar[largest]=ar[i];
				ar[i]=temp;
				max_heapify(ar,heap_size,largest);
		}
	}
	else if(hasRight==false)
	{
		if(ar[2*i] >ar[i])
		{
			int temp=ar[i];
			ar[i]=ar[2*i];
			ar[2*i]=temp;
			max_heapify(ar,heap_size,2*i);
		}
	}
}
void build_max_heap(int ar[],int n);
{
	int heap_size=n-1;
	for(int i=n/2;i>=0;i--)
	{
			max_heapify(ar,heap_size,i);
}
int delete_max(int ar[],int heap_size)
{
	int val=ar[0];
	int temp=ar[0];
	ar[0]=ar[heap_size-1];
	ar[heap_size-1]=temp;
	heap_size--;
	if(heap_size!=0)
	max_heapify(ar,heap_size,0);
	return val;
}
int return_max(int ar[],int heap_size)
{
	if(heap_size>0)
	return ar[0];
}
int main()
{
	int heap_size=20;
	int ar[20];
	for(int i=0;i<20;i++)
		cin>>ar[i];
	build_heap(ar,heap_size);
	int n;  // no. of queries :)
	for(int i=0;i<n;i++)
		cout<< deletemax(ar,heap_size);
	return 0;
}
