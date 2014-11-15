#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
#define MAXIND 530000
#define MAXN 100010
int A[MAXN],M[MAXIND];
void initialize(int node, int b, int e, int M[MAXIND], int A[MAXN], int N)
  {
      if (b == e)
          M[node] = b;
      else
       {
          initialize(2 * node, b, (b + e) / 2, M, A, N);
          initialize(2 * node + 1, (b + e) / 2 + 1, e, M, A, N);
  
          if (A[M[2 * node]] >= A[M[2 * node + 1]])
              M[node] = M[2 * node];
          else
              M[node] = M[2 * node + 1]; 
      }
} 
int query(int node, int b, int e, int M[MAXIND], int A[MAXN], int i, int j)
{
      int p1, p2;
      if (i > e || j < b)
          return -1;
      if (b >= i && e <= j)
          return M[node];
      p1 = query(2 * node, b, (b + e) / 2, M, A, i, j);
      p2 = query(2 * node + 1, (b + e) / 2 + 1, e, M, A, i, j);
      if (p1 == -1)
          return M[node] = p2;
      if (p2 == -1)
          return M[node] = p1;
      if (A[p1] >= A[p2])
          return M[node] = p1;
      return M[node] = p2;

}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	for(int i=0;i<MAXIND;i++)
		M[i]=-1;
	initialize(1,0,n-1,M,A,n);	
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int res=query(1,0,n-1,M,A,l,r);
		cout<<A[res]<<endl;
	}
	
}
