#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <inttypes.h>
#include <math.h>
#define MOD 1000000007
unsigned int BitsSetTable256[256] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,1,2,2,3,2,3,3,4,
2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,
4,5,5,6,5,6,6,7,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,2,3,3,4,3,4,4,5,
3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8};
using namespace std;
#define ULL unsigned long long int
ULL count_bit(ULL n);
typedef unsigned long long ull;
class matrix
{
	public:
		ull a,b,c,d;
		matrix()
		{
			a=b=c=1;
			d=0;
		}
		matrix mul(matrix a,matrix b)
		{
			matrix ret;
			ret.a=(a.a*b.a)+(a.b*b.c);
			ret.b=(a.a*b.b)+(a.b*b.d);
			ret.c=(a.c*b.a)+(a.d*b.c);
			ret.d=(a.c*b.b)+(a.d*b.d);
			return ret;
		}
		matrix modMat(matrix a)
		{
			a.a=(a.a)%MOD;
			a.b=(a.b)%MOD;
			a.c=(a.c)%MOD;
			a.d=(a.d)%MOD;
			return a;
		}
		matrix exp(matrix a,ull p)
		{
			if(p==0){
				matrix temp;
				temp.a=temp.b=temp.c=temp.d=1;
				return temp;
			}
			if(p==1)
				return a;
			if(p%2==0)
				return exp(modMat(mul(a,a)),p/2);
			else
				return modMat(mul(a,exp(modMat(mul(a,a)),(p-1)/2)));
		}
		ull fib(ull n)
		{
			matrix s;
			s=exp(s,n);
			return (s.d);
		}
};
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		matrix v;
		int n;
		int g;
		scanf("%d %d",&n,&g);
		ULL n2;
		int count=0;
        	if(n==0)
        	count=1;
        	else{
        	
			n2=v.fib(n+2);
			count=count_bit(n2);
			}
		if(count == g)
		printf("CORRECT\n");
		else
		printf("INCORRECT\n");

	}
	return 0;
}
ULL count_bit(ULL v)
{
	ULL c;
	c = BitsSetTable256[v & 0xff] + 
    BitsSetTable256[(v >> 8) & 0xff] + 
    BitsSetTable256[(v >> 16) & 0xff] + 
    BitsSetTable256[v >> 24]; 
    return c;
}             
                         
