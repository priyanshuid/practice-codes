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
#include <inttypes.h>
using namespace std;
int main()
{
	unsigned long long a,b;
	while(scanf("%llu %llu",&a,&b)!=EOF)
	{
		
		unsigned long long  dif;
		if(a>b)
		 dif=a-b;
		else
		dif = b-a;
		cout<<dif<<endl;
		
	}
	return 0;
}

