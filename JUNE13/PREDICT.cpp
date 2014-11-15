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
	int t;
	scanf("%d",&t);
	int val1,val2;
	for(int t1=0;t1<t;t1++)
	{
		double pA;
		scanf("%lf",&pA);
		if(pA<.5)
		pA=1-pA;
		double val=pA*(10000+10000*(2*(1-pA)));
		 std::cout.setf( std::ios::fixed, std:: ios::floatfield ); 
		std::cout.precision(10);
		cout<<val<<endl;
	}
	return 0;
}

