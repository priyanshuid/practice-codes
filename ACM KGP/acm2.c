#include <stdio.h>
int main()
{
	int t,t1,i,j;
	int ar1[110],ar2[110];
	scanf("%d",&t);
	while(t-->0)
	{
		int n;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&ar1[i]);
		int m;
			scanf("%d",&m);
		for(j=0;j<m;j++)
				scanf("%d",&ar2[j]);
		int count=0;
		i=0;j=0;
		while (i < n && j < m) {
 
			if (ar1[i] < ar2[j]) {
				i++;
			} else if (ar1[i] > ar2[j]) {
				j++;
			} else {
				count++;
				i++;
				j++;
			}
		}
 
		if(m>=n)
		{
			m=2*m-n-count;
			printf("%d\n",m);
			}
		else
		{
			n=n-count;
			printf("%d\n",n);
			
		}
		
	}
	return 0;
	
}

