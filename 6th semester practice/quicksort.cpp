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
#include <time.h> 
using namespace std;
int sortQuick(int ar[],int l,int r);
void quicksort(int ar[],int l,int r)
{
	if(l<r)
	{
		int pi=sortQuick(ar,l,r);
		quicksort(ar,l,pi-1);
		quicksort(ar,pi+1,r);
	}
}
int sortQuick(int ar[],int l,int r)
{
	int pivot=l;
	int j=l+1;
	for(int i=l+1;i<=r;i++)
	{
		if(ar[i]<ar[pivot])
		{
			int temp=ar[i];
			ar[i]=ar[j];
			ar[j]=temp;
			j++;
		}	
	}
	j--;
	int temp=ar[pivot];
	ar[pivot]=ar[j];
	ar[j]=temp;
	return pivot;
}
int main()
{
	int ar[10];
	for(int i=0;i<10;i++)
	{
			
			cin>>ar[i];
	}
	quicksort(ar,0,9);
	cout<<endl;
	for(int i=0;i<10;i++)
		cout<<ar[i]<<" ";
	return 0;
}

