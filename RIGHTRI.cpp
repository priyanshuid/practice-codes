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
	int n;
	cin>>n;
	int count=0;
	for(int i=0;i<n;i++)
	{
		int x1,x2,x3;
		int y1,y2,y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		int d1=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
		int d2=(x2-x3)*(x2-x3)+(y2-y3)*(y2-y3);
		int d3=(x1-x3)*(x1-x3)+(y1-y3)*(y1-y3);
		if(d1+d2==d3 || d2+d3==d1 || d1+d3==d2)
		count++;	
	}
	cout<<count<<endl;
	return 0;
}


