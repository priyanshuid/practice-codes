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
using namespace std;
int gcd(int a,int b)
{
	long long int temp;
	while(b!=0)
	{
		temp=b;
		b=a%temp;
		a=temp;
	}
	return a;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
	{
    	
		int n,m;
		cin>>n>>m;
		if(n!=1 && m!=1)
		{
		
			int gv=gcd(n,m);
    	    int cn = n/gv;
    		int rn= m/gv;
 			int val=(n-2)/cn;
    		val=min(val,(m-2)/rn);
    		cout<<val+2<<endl;
    	}
    	else
    	{
    		int v=n*m;
    		cout<<v<<endl;
    	}
    }
    return 0; 
}
