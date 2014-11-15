#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#define MAXN 100010
#define LOGMAXN 102
#define getcx getchar_unlocked()
typedef unsigned long long ull;
using namespace std;
int input()
{
int t=0;
char c;
c=getchar_unlocked();
while(c<'0' || c>'9')
c=getchar_unlocked();
while(c>='0' && c<='9')
{
t=(t<<3)+(t<<1)+c-'0';
c=getchar_unlocked();
}
return(t);
}
ull A[MAXN],M[MAXN][LOGMAXN],M1[MAXN][LOGMAXN];

void process1(ull M1[MAXN][LOGMAXN], ull A[MAXN], int N)//maxm//
{
     int logN = log2(N);

	for(int i=0; i<N; ++i)
        M1[i][0] = i;
   
    for(int j=1; (1<<j) <= N; ++j)
    {
        for(int i=0; i+(1<<j)-1 < N; ++i)
        {
            if(A[M1[i][j-1]] >= A[M1[i+(1<<(j-1))][j-1]])
                M1[i][j] = M1[i][j-1];
            else
                M1[i][j] = M1[i+(1<<(j-1))][j-1];
        }
      }
}  
void process2(ull M[MAXN][LOGMAXN], ull A[MAXN], int N)//min//
{
     int logN = log2(N);

	for(int i=0; i<N; ++i)
        M[i][0] = i;
   
    for(int j=1; (1<<j) <= N; ++j)
    {
        for(int i=0; i+(1<<j)-1 < N; ++i)
        {
            if(A[M[i][j-1]] <= A[M[i+(1<<(j-1))][j-1]])
                M[i][j] = M[i][j-1];
            else
                M[i][j] = M[i+(1<<(j-1))][j-1];
        }
      }
}  
int RMQ(ull *A, int size, int i, int j)
{
    int k=0;
    k=log2(j-i+1);

    if(A[M[i][k]] <= A[M[j-(1<<k)+1][k]])
        return A[M[i][k]];
    else
        return A[M[j-(1<<k)+1][k]];
}
int RMQ2(ull *A, int size,int i, int j)//max//
{
    int k=0;
    k=log2(j-i+1);

    if(A[M1[i][k]] >= A[M1[j-(1<<k)+1][k]])
        return A[M1[i][k]];
    else
        return A[M1[j-(1<<k)+1][k]];
}
int main()
{
	int n;
	n=input();
	for(int i=0;i<n;i++)
		{
			A[i]=input();
		}
	process2(M,A,n);
	process1(M1,A,n);
	int q;
	q=input();
	for(int i=0;i<q;i++)
	{
		int l,r;
		l=input();
		r=input();
		int max1=0,max2=0;
		if(l>0)
			max1=RMQ2(A,n,0,l-1);
		if(r<n-1)
			max2=RMQ2(A,n,r+1,n-1);
		int min=RMQ(A,n,l,r);
		int max4=RMQ2(A,n,l,r);
		double d0=min+(double)(max4-min)/2;
		double d1=min+max1;
		double d2=max2+min;
		double d3=d1>d2?d1:d2;
		double ans=d0>d3?d0:d3;
		cout.setf(std::ios::fixed);
    	cout.precision(1);
		cout<<ans<<endl;
	}
	return 0;
}
