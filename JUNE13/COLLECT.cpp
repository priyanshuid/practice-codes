#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <math.h>
#include <map>
#define unsigned long long ull
#include <stdio.h>
#include <math.h>
#define M 3046201
using namespace std;
long long int fact[3000010];
long long int infact[3000010];
long long pow(int a, int b, int MOD)
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
long long mod_inv(int n, int MOD)
{
    return pow(n,MOD-2,MOD);
}
void fctrl(long long int *fact)
{
	fact[0]=1;
	fact[1]=1;
	for(int i=1;i<3000010;i++)
		fact[i]=(fact[i-1]*i)%M;
}
void rev_fctrl(long long int *infact)
{
	infact[0]=1;
	infact[1]=1;
	for(int i=1;i<1000010;i++)
		infact[i]=(mod_inv(i,M)*infact[i-1])%M;
}
int getMid(int s, int e) {  return s + (e -s)/2; } 
int getSumUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return 0;
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*index+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*index+2);
}
void updateValueUtil(int *st, int ss, int se, int i, int diff, int index)
{
    if (i < ss || i > se)
        return;
    st[index] = st[index] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*index + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*index + 2);
    }
}
void updateValue(int arr[], int *st, int n, int i, int new_val)
{
    int diff = new_val - arr[i];
    arr[i] = new_val;
    updateValueUtil(st, 0, n-1, i, diff, 0);
}
int getSum(int *st, int n, int qs, int qe)
{
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}
int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}
int *constructST(int arr[], int n)
{
 
    int x = (int)(ceil(log2(n))); 
    int max_size = 2*(int)pow(2, x) - 1;
    int *st = new int[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
     for(int i=0;i<max_size;i++)
    	cout<<st[i]<<" ";
    	cout<<endl;
    return st;
}
int main()
{

	int v;
	cin>>v;
    int ar[v];
    for(int i=0;i<v;i++)
    	scanf("%d",&ar[i]);
    int *st = constructST(ar,v);
    int q;
    cin>>q;
    fctrl(fact);
 //	rev_fctrl(infact);
	string a;
    getline(cin,a);
    for(int i=0;i<q;i++)
    {
		string a;
		cin>>a;
		
		if(a=="change")
		{
			int a, b;
			cin>>a>>b;
			updateValue(ar,st,v,a-1,b);
		}
	
		else if(a=="query")
		{
			int a,b;
			cin>>a>>b;
			int sum=getSum(st,v,a-1,b-1);
			cout<<sum<<endl;
			int MOD=3046201;
			int range=b-a+1;
			long long a1,b1,r,R,ans;
        	a1=sum/range;
       		r=sum%range;
        	if(r)b1=a1+1;
        	else b1=0;
        	R=range-r;
        	a1=pow(fact[a1],R,MOD);
        	a1=pow(a1,MOD-2,MOD);
        	b1=pow(fact[b1],r,MOD);
        	b1=pow(b1,MOD-2,MOD);
        	r=pow(fact[r],MOD-2,MOD);
        	R=pow(fact[R],MOD-2,MOD);
        	ans=((((((fact[sum]*fact[range])%MOD)*((a1*b1)%MOD))%MOD)*((r*R)%MOD))%MOD+MOD)%MOD;
        	cout<<ans<<endl;
		} 
	}
    return 0;
}


