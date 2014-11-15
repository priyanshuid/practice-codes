#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main()
{
	int a[]={1,3,2,6,2};
	int b[6];
	int c[7];
	for(int i=0;i<7;i++)
	c[i]=0;
	for(int j=0;j<6;j++)
		c[a[j]]++;
	for(int i=1;i<5;i++)
		c[i]=c[i]+c[i+1];
	for(int j=5;j>=0;j++)
	{
		b[c[a[j]]]=a[j];
		c[a[j]]--;
	}
	return 0;
}
