#include<stdio.h>
 
int main()
{
	long int t,i;
	unsigned long long int n,ans,val;
 
	unsigned long long int a[]={0,1, 2, 3, 6, 10, 20, 35, 70, 126, 252, 462, 924, 1716, 3432, 6435, 12870, 24310, 48620, 92378, 184756, 352716, 705432, 1352078, 2704156, 5200300, 10400600, 20058300, 40116600, 77558760, 155117520, 300540195, 601080390, 1166803110, 2333606220, 4537567650, 9075135300, 17672631900, 35345263800, 68923264410, 137846528820, 269128937219, 538257874439, 1052049481860, 2104098963720, 4116715363800, 8233430727600, 16123801841549, 32247603683099, 63205303218876, 126410606437752, 247959266474052, 495918532948104, 973469712824056, 1946939425648112, 3824345300380220, 7648690600760440, 15033633249770519, 30067266499541039, 59132290782430711, 118264581564861423, 232714176627630544, 465428353255261088, 916312070471295267, 1832624140942590534, 3609714217008132870, 7219428434016265740, 14226520737620288368, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
 
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%llu",&n);
	//	ans = (n*(n-1))/2;
	/*	if(n>2)
		{		
			val = (unsigned long long int) sqrt(2+(8*n));
			ans = (unsigned long long int) (val+1)/2;
			if((val*val)==(1+ 8*n))
				printf("%llu\n",ans);
			else
				printf("%llu\n",ans+1);
		}
		else
			printf("2\n");*/
 
		for(i=2;i<80;i++)
		{
			if(n<=a[i])
			{
				printf("%d\n",i);
				i=89;
			}
		}
	}
	return 0;
}