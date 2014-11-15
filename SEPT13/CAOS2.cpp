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
int primes[]={2,3,5,7,  11,  13,  17,  19,  23,  29,  31,  37,  41,43,  47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97, 101,

 	103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167,
 	173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239,

 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313,
 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,

 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467,
 479, 487, 491, 499};
int ltp[501];
void prime_less_than_equal_to()
{
	int k=0,p=0;
	for(int i=0;i<501;i++)
	{
		if(k<95 && i==primes[k])
		{
			k++;
			p++;
		}
		ltp[i]=p;	
	}
//	for(int i=0;i<501;i++)
//	cout<<ltp[i]<<" ";
}
int find_min(int a,int b,int c,int d)
{
	int ar[]={a,b,c,d};
	int min=ar[0];
	for(int i=1;i<4;i++)
	{
		if(ar[i]<min)
		min=ar[i];
	}
	return min;
}
int main()
{
	int t;
	scanf("%d",&t);
	prime_less_than_equal_to(); 
	for(int t1=0;t1<t;t1++)
	{
		int rw,cn;
		scanf("%d%d",&rw,&cn);
		char ar[rw][cn];
		int top[rw][cn];
		int down[rw][cn];
		int left[rw][cn];
		int right[rw][cn];
		memset(top,0,sizeof(top));
		memset(top,0,sizeof(down));
		memset(top,0,sizeof(left));
		memset(top,0,sizeof(right));
		for(int i=0;i<rw;i++)
		{
			for(int j=0;j<cn;j++)
			//string str;
			//int j=0;
			//cin>>str;
		//	int l=str.length();
		//	while(j<l)
			cin>>ar[i][j];
		}
		int count=0;
		for(int i=0;i<rw;i++)
		{
			for(int j=0;j<cn;j++)
			{
				if(ar[i][j]=='#')
					right[i][j]=-1;
				else if(ar[i][j]=='^')
				{
					if(j==0)
						right[i][j]=0;
					else
					{
						
					if(right[i][j-1]>=0)
						right[i][j]=right[i][j-1]+1;
					else
						right[i][j]=0;
					}
				}
			}
		}
		for(int i=0;i<rw;i++)
		{
			for(int j=cn-1;j>=0;j--)
			{
				if(ar[i][j]=='#')
				left[i][j]=-1;
				else if(ar[i][j]=='^')
				{
					if(j==cn-1)
						left[i][j]=0;
					else
					{
						if(left[i][j+1]>=0)
							left[i][j]=left[i][j+1]+1;
						else
							left[i][j]=0;
					}
				}
			}
		}
		for(int j=0;j<cn;j++)
		{
			for(int i=0;i<rw;i++)
			{
				if(ar[i][j]=='#')
					top[i][j]=-1;
				else if(ar[i][j]=='^')
				{
					if(i==0)
						top[i][j]=0;
					else 
					{
						if(top[i-1][j]>=0)
							top[i][j]=top[i-1][j]+1;
						else
							top[i][j]=0;
					}
				}
			}
		}
		for(int j=0;j<cn;j++)
		{
			for(int i=rw-1;i>=0;i--)
			{
				if(ar[i][j]=='#')
					down[i][j]=-1;
				else if(ar[i][j]=='^')
				{
					if(i==rw-1)
						down[i][j]=0;
					else
					{
						if(down[i+1][j]>=0)
							down[i][j]=down[i+1][j]+1;
						else
							down[i][j]=0;
					}
				}
			}
		}
		for(int i=0;i<rw;i++)
		{
			for(int j=0;j<cn;j++)
			{
			//	cout<<top[i][j]<<" "<<down[i][j]<<" "<<right[i][j]<<" "<<left[i][j]<<endl;
				int min=find_min(top[i][j],down[i][j],left[i][j],right[i][j]);
				if(min>=2)
				count+=ltp[min];
			}
		}
		printf("%d\n",count);
	}
	return 0;
}

