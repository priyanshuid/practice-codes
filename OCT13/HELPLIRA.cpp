#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int max_indx=1,min_indx=1;
	int max_area,min_area;
	for(int i=1;i<=n;i++)
	{
		int x1,y1;
		int x2,y2;
		int x3,y3;
		scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
		int area=x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2);
		if(area<0)
			area=-area;
		if(i==1 || area>=max_area)
		{
			max_indx=i;
			max_area=area;
		}
		if(i==1 || area<=min_area)
		{
			min_indx=i;
			min_area=area;
		}
	}
	printf("%d %d",min_indx,max_indx);
	return 0;
}
