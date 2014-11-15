#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include<vector>
#define  ull unsigned long long int
#define MOD 1000000007
long long int power(long long int a, long long int b);
long long pow(int a, int b,int mod);
long long InverseEuler(int n, int mod);
long long C(int n, int r, int mod);
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int y=0;y<t;y++)
	{
		ull n;
		int k;
		cin>>n;
		for(int i=0;i<n;i++)
			scanf("%d",&k);
		ull t1;
		t1=power(2,n-1);
		
	//	cout<<t1<<endl;
		if(n%2!=0)
		cout<<t1<<endl;
		else
		{
			int g=n/2+1;
			ull sum=0;
			for(int j=g;j<n;j++)
			sum=(sum+(C(n,j,MOD))%MOD)%MOD;
					//	cout<<t4<<endl;
			cout<<sum+1<<endl;
		}
	}
	return 0;
}
long long int power(long long int a, long long int b)
{
	if(b==0)
		return 1;
	else if(b==1)
		return a%MOD;
	else if(b%2==0)
		return power((a*a)%MOD,b/2);
	else
		return (a*power((a*a)%MOD,b/2))%MOD;
}                    
long long pow(int a, int b, int mod)
{
    long long x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}
long long InverseEuler(int n, int mod)
{
    return pow(n,MOD-2,MOD);
}
long long C(int n, int r, int mod)
{
    vector<long long> f(n + 1,1);
    for (int i=2; i<=n;i++)
        f[i]= (f[i-1]*i) % MOD;
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}                
