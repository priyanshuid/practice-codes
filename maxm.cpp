// MAXIMUM ELEMENT / MINIMUM ELEMENT CAN BE FOUND IN LINEAR TIME
#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
	vector <int>ar;
	int k;
	do
	{
		cin>>k;
		ar.push_back(k);
	}while(k!=0);
	int max=ar[0];
	int min=ar[0];
	for(int i=1;i<ar.size()-1;i++)
	{
		if(ar[i]>max)
			max=ar[i];
		else if(ar[i]<min)
			min=ar[i];
	}
	cout<<"MAXIMUM ELEMENT:"<<max <<endl;
	cout<<"MINIMMUM ELEMENT:"<<min <<endl;
	return 0;
}
