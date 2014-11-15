#include <stdio.h>
int main()
{
	int t,t1;
	scanf("%d",&t);
	for(t1=0;t1<t;t1++)
	{
	 	int T1,T2,T3,T4;
		scanf("%d%d%d%d",&T1,&T2,&T3,&T4);
		double k=(double)T1/(double)(T1+T2);
		printf("%.6lf\n",k);
	}
	return 0;
}

