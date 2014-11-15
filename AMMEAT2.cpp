#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++)
	{
	    int n,k;
		cin>>n>>k;
		if(k>=(n/2)+1)
			cout<<"-1"<<endl;
		else
		{
			int i=2,count=0;
			while(count<k)
			{
				cout<<i<<" ";
				i+=2;
				count++;
			}
			cout<<endl;
		}
	}
	return 0;
}
