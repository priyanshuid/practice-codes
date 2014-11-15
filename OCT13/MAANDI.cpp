#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		int count=0;
		for(int i=1;i<=(int)sqrt(n);i++)
		{
			if(n%i==0)
			{	
				int n1=i;
				int n2=(int)n/i;
				while(n1!=0)
				{
					int g=n1%10;
					n1=n1/10;
					if(g==4 || g==7)
					{
						count++;
						break;
					}
				}
				while(n2!=0)
				{
					int g=n2%10;
					n2=n2/10;
					if(g==4 || g==7)
					{
						count++;
						break;
					}
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
