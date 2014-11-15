//quick sort
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

#typedef fl0(n) for(int i=0;i<n;i++)
#typedef fl1(a,b) for(int i=a;i<b;i++)

int quick_sort(int ar[],int start,int end)
{
	int val=ar[start];
	int i=sta;rt;
	for(int j=start+1;j<end;j++)
	{
		if(ar[j]<=val)
		{
			i++;
			int temp=ar[i];
			ar[i]=ar[j];
			ar[j]=temp;
		}
	}
	int temp=ar[start];
		ar[start]=ar[i];
		ar[i]=temp;
		
	return i;
}
int main()
{
	int n,j=0;
	cout>>"Enter the elaments ending with -1";
	int *ar=new int[5];
	int ar[0]=0;
	while(ar[j]!=0)
		cin>>ar[j++];
	
	
}
