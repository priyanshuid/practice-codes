#include <stdio.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	for(int t1=0;t1<t;t1++)
	{
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		if(n==1 && m==1)
		{
			cout<<0<<endl;
		}
		else if(n==1 && m==2)
		{
				cout<<0<<endl;
		}
		else if(n==2 && m==1)
		{
				cout<<0<<endl;
		}
		else if(n==1 || m==1)
		cout<<k<<endl;
		else
		{
		if(k%2==0)
		cout<<k/2<<endl;
		else
		cout<<k/2+1<<endl;
		}
	}
	return 0;
}

