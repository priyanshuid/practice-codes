#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
int main()
{
	int c;
	cin>>c;
	for(int i=0;i<c;i++)
	{
		int n,m,t;
		cin>>n>>m>>t;
		int v=2*t*ceil(n/(float)m);
		cout<<v<<endl;
	}
	return 0;
}
