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
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++)
	{
		int n,k,ans;
		cin>>n>>k>>ans;
		int ar[n];
		for(int i=0;i<n;i++)
		{
				cin>>ar[i];				
		}
	
		string str;
		cin>>str;
		if(k!=0)
		{
			
			if(str=="OR")
			{
				for(int i=0;i<n;i++)
				ans=ans|ar[i];
			}
			else if(str=="AND")
			{
					for(int i=0;i<n;i++)
				{
					ans=ans&ar[i];
					}
			}
			else
			{
				int val=ar[0];
				for(int i=1;i<n;i++)
				val=val^ar[i];
				if(k%2==0)
					ans=ans;
				else
				ans=val^ans;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

