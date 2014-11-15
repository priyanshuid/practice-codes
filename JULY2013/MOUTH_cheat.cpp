#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <math.h>
#include <memory.h>
#include <map>
#define unsigned long long ull
#define gc getchar_unlocked
using namespace std;
int suf_ar[100001],lcp_ar[100001],g[100001],r[100001],diff[100001];
int h;
bool compare(const int &i, const int &j)
{
    return (r[i]<r[j]) || (r[i]==r[j] && r[i+h]<r[j+h]);
}
void sar(int diff[],int n)  
{
    int i=0;
    for(i=0;i<n;i++)
    {
        suf_ar[i]=i;
        r[i]=diff[i];
    }
    h=0;
    sort(suf_ar,suf_ar+n,compare);
    g[0]=0;
    for(h=1;;h=h*2)
    {
        sort(suf_ar,suf_ar+n,compare);
        for(i=1;i<n;i++)
        g[i]=g[i-1]+compare(suf_ar[i-1],suf_ar[i]);
        for(i=0;i<n;i++)
        r[suf_ar[i]]=g[i];
        if(g[n-1]==n-1)
        break;
    }
}
 
void lar(int n)        
{
        int l=0,k,m,j,i;
        lcp_ar[0]=0;
        for(j=0;j<n-1;j++)
        {
            k=r[j];
            m=suf_ar[k-1];
            while(diff[j+l]==diff[m+l])
            ++l;
            lcp_ar[k]=l;
            if(l>0)
                --l;
        }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int t1=0;t1<t;t1++)
    {
		int val=0,n;       
	    memset(suf_ar,0,sizeof(suf_ar));
        scanf("%d",&n);
        int ar[n];
        memset(diff,0,sizeof(diff));
		memset(lcp_ar,0,sizeof(lcp_ar));
        memset(r,0,sizeof(r));
        memset(g,0,sizeof(g));
        int i;
    	for( i=0;i<n;i++)
        {   
			scanf("%d",&ar[i]);
            if(i!=0)
            diff[i-1]=ar[i]-ar[i-1];
        }
        diff[i-1]=-101;
        sar(diff,n);
        lar(n);
        for( i=1;i<n;i++)
           val=(val+(n-1-suf_ar[i])-lcp_ar[i])%1000000009; 
        printf("%d\n",val);
    }
    return 0;
}
