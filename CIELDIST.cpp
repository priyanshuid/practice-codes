#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int b=0;b < t;b++)
	{
		double ds1,dt1,d1;
		cin>>ds1>>dt1>>d1;
		if(d1>(ds1+dt1))
			{
			cout.setf(ios::fixed);
		    cout.precision(6);
			cout<<d1-(ds1+dt1)<<endl;
			}
		else
			{
				//double d=(double)d1,ds=(double)ds1,dt=(double)dt1;
				double d=d1,ds=ds1,dt=dt1;
				double r=fabs(sqrt(fabs(ds*ds-(d/2)*(d/2)))-sqrt(fabs(dt*dt-(d/2)*(d/2))));
				cout.setf(ios::fixed);
    			cout.precision(6);
    			cout << r<<endl;
				
			}
	}
}
