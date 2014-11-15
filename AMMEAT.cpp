#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
typedef unsigned long long int ull;
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++)
	{
	   ull n,m;
	   scanf("%llu %llu",&n,&m);
	   ull ar[n];
	   for(ull i=0;i<n;i++)
	   	    scanf("%llu",&ar[i]);
		ull *start=&ar[0];
		ull *end=&ar[n];
		sort(start,end);
		ull sum=0;
		int count=0;
		int k=n-1,flag=0;
		while(k>=-1)
		{
             if(sum >=m)
             {
              flag=1;
			  break;
              }
			 sum+=ar[k];
			 k--;
			 count++;
			
			 			
		}
		if(k==-2 && flag!=1)
		     cout<<-1<<endl;
	    else 
	    	cout<<count<<endl;
	}
	return 0;
}
