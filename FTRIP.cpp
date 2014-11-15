#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;
int main()
{
	int ar[1000][1000];
	for(int i=0;i<1000;i++)
	{
		for(int j=0;j<1000;j++)
		{
			ar[i][j]=1;
			cout<<ar[i][j];
		}
	}
	return 0;
}
