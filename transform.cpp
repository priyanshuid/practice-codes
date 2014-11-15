#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <ctype.h>
#define PIE 3.14
using namespace std;
double area(double val)
{
	double v=val*val*PIE;
	return v;
}
int main()
{
	vector<double> val;
	for(int i=0;i<10;i++)
		val.push_back(i);
	vector<double>::iterator p;
	p=val.begin();
	p=transform(val.begin(),val.end(),val.begin(),area);
	p=val.begin();
	while(p!=val.end())
	{
		cout<<*p<<endl;
		p++;
	}
	return 0;
}
