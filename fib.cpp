#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <inttypes.h>
#include <math.h>
using namespace std;
unsigned long long int f[2][2],m[2][2]={1,1,1,0};
void power(unsigned long long int n);
void multiply(unsigned long long int m[2][2]);
unsigned long long int fib(unsigned long long int n)
{
    
	 f[0][0]=1;        f[1][0]=1;
     f[0][1]=1;        f[1][1]=0;
     if(n==0)
             return(0);
     power((n));
     return(f[0][0]%1000000007);
     }
void power(unsigned long long int n)
{
     if(n==0||n==1)
                   return;
     power((n/2));
     multiply(f);
     if(n%2!=0)
     multiply(m);
     }
void multiply(unsigned long long int m[2][2])
{
     unsigned long long int w,x,y,z;
     w=((f[0][0]*m[0][0])+(f[0][1]*m[1][0]))%1000000007;
     x=((f[0][0]*m[0][1])+(f[0][1]*m[1][1]))%1000000007;
     y=((f[1][0]*m[0][0])+(f[1][1]*m[1][0]))%1000000007;
     z=((f[1][0]*m[0][1])+(f[1][1]*m[1][1]))%1000000007;
    /* w=((f[0][0])+(f[0][1]))%1000000007;
     x=((f[0][0]))%1000000007;
     y=((f[1][0]+(f[1][1])))%1000000007;
     z=((f[1][0]))%1000000007;*/
     f[0][0]=w;
     f[0][1]=x;
     f[1][0]=y;
     f[1][1]=z;
     }
 
int main()
{
    unsigned long long int t,n,ans;
	cin>>t;
	while(t--){
	
	cin>>n;
	ans=fib(n);
	cout<<ans<<endl;}
}
