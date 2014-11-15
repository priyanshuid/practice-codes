#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int ar1[100001];
	for(int t3=2;t3<=100001;t3++)
		{
		int count=0;
		if(t3==2)
		count=1;
		else
		{
			int n=t3;
			int z=2;
			int k=0;
			
			int u=0;
			 while (z*z<=n)
			 {
			 	
				 if(n%z==0)
			 	{
					 if(u!=z)
					 count++;
			 		n/=z;
			 		u=z;		 		
			 	}
			 	else
			 	{
			 		z++;
			 	}
			 	
			 }
				if(n!=z)
				count++;
		}
		ar1[t3]=count;
	}
	int t;
	scanf("%d",&t);
	for(int t2=0;t2<t;t2++)
	{
		int a,b,k;
		int count1=0;
		scanf("%d%d%d",&a,&b,&k);
		for(int t1=a;t1<=b;t1++)
		{
	/*	int count=0;
		if(t1==2)
		count=1;
		else
		{
			int n=t1;
			int z=2;
			int k=0;
			
			int u=0;
			 while (z*z<=n)
			 {
			 	
				 if(n%z==0)
			 	{
			 		//int n1=n;
					 if(u!=z)
					 count++;
			 		n/=z;
			 		u=z;		 		
			 	}
			 	else
			 	{
			 		z=ar[++k];
			 	}
			 	
			 }
				if(n!=z)
				count++;
		}
			if(count==k)*/
			
			if(ar1[t1]==k)
			count1++;
		}
		printf("%d\n",count1);
	
	}
	
}

