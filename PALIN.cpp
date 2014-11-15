#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <math.h>
#include <map>
#define unsigned long long ull
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++)
	{
		char ar[1000005];
		scanf("%s",&ar);
		int k=0;
		while(ar[k])
			k++;
		int flagp=0;
		for(int i=0;i<k;i++)
		{
			if(ar[i]!='9')
			{
				flagp=1;
				break;
			}
		}
		if(flagp==1)
		{
			if(k%2==0)
			{
				int gflag=0;
				for(int i=k-1;i>=k/2;i--)
				{
					if(ar[i]!=ar[k-i-1])
					{
						gflag=1;
						break;
					}
				}
				
				if(gflag==0)
				{
					int h=k/2;
					while(ar[h]=='9')
					{
						ar[h]='0';
						ar[k-1-h]='0';
						h++;
					}
					ar[h]++;
					ar[k-1-h]++;
				}
				else
				{
						
					for(int i=k-1;i>=k/2;i--)
					{
						if(ar[i]>ar[k-1-i])
						{
							
							int h=i-1;
							while(ar[h]=='9')
							{
								ar[h]='0';
								h--;
							}
							if(h==0)
							ar[k-1]++;
							ar[h]++;
							ar[i]=ar[k-1-i];
								
						}
						else if(ar[i]<ar[k-1-i])
						ar[i]=ar[k-1-i];
					}
				}
			}
			else
			{
				int flag=0;
				for(int i=k-1;i>k/2;i--)
				{
					if(ar[i]!=ar[k-i-1])
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					int h=k/2;
					while(ar[h]=='9')
					{
						ar[h]='0';
						ar[k-h-1]='0';
						h--;
					}
					ar[h]++;
					if(h!=k/2)
					ar[k-1-h]++;
				}
				
				else
				{
					for(int i=k-1;i>k/2;i--)
					{
						if(ar[i]>ar[k-1-i])
						{
							
							int h=i-1;
							while(ar[h]=='9')
							{
								ar[h]='0';
								h--;
							}
							if(h==0)
							ar[k-1]++;	
							ar[h]++;
							ar[i]=ar[k-1-i];	
						}
						else if(ar[i]<ar[k-1-i])
						ar[i]=ar[k-1-i];
						
					}
				
				}
			}
			printf("%s\n",ar);
		}
		else
		{
				for(int i=0;i<k-1;i++)
				ar[i]='0';
				ar[k-1]='1';
				printf("1%s\n",ar);
			
		}
	}
}

