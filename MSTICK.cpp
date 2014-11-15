#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
void initialize(int node, int b, int e, int M[MAXIND], int A[MAXN], int N)
{
      if (b == e)
          M[node] = b;
      else
       {
          initialize(2 * node, b, (b + e) / 2, M, A, N);
          initialize(2 * node + 1, (b + e) / 2 + 1, e, M, A, N);
          if (A[M[2 * node]] <= A[M[2 * node + 1]])
              M[node] = M[2 * node];
          else
              M[node] = M[2 * node + 1]; 
      }
}
int main()
{
	int n;
	scanf("%d",&n);
	vector <int> mstk;
	for(int i=0;i<n;i++)
		{
			int temp;
			scanf("%d",&temp);
			mstk.push_back(temp);
		}
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int min=minlement(mstk,l,r);
		int max=maxlement(mstk,l,r);
		double d1=min+((double)(max-min))/2;
		int max2;
		if(l==0)
			max2=-1;
		else
			max2=maxlement(mstk,0,l-1);
		int max3=maxlement(mstk,r+1,n-1);
		int max4=max2>max3?max2:max3;
		double d2=min+max4;
		double d=d2>d1?d2:d1;
		if((int)d==d)
			cout<<d<<".0"<<endl;
		else
			cout<<d<<endl;
		
	}
	return 0;
}

