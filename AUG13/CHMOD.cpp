/*Segment tree structure is made from the help from http://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range */
/*  fast i/o http://www.codechef.com/viewsolution/916981 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <math.h>
#include <map>
#define unsigned long long ull
#define gc getchar_unlocked
#include <unistd.h>
 
#define BS 64*1024
 
char ibuffer[BS];
int ibuffer_offset=0;
int ibuffer_size=0;
 
char obuffer[BS];
int obuffer_offset=0;
 
static int inline fastread() {
int r=0, s=1;
while(1) {
if(ibuffer_offset >= ibuffer_size) {
ibuffer_size = read(0, ibuffer, BS);
ibuffer_offset = 0;
}
if(ibuffer[ibuffer_offset] < 48) {
if(s) ibuffer_offset++;
else return r;
}
else {
s = 0;
r = r * 10 + ibuffer[ibuffer_offset++]-48;
}
}
}
 
void inline flush() {
write(1, obuffer, obuffer_offset);
obuffer_offset = 0;
}
 
static const char *rd[31] = {
"1\n", "2\n", "4\n", "8\n", "16\n", "32\n", "64\n", "128\n", "256\n", "512\n", "1024\n",
"2048\n", "4096\n", "8192\n", "16384\n", "32768\n", "65536\n", "131072\n", "262144\n",
"524288\n", "1048576\n", "2097152\n", "4194304\n", "8388608\n", "16777216\n",
"33554432\n", "67108864\n", "134217728\n", "268435456\n", "536870912\n"};
static const int rl[31] = {2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10};
 
 
static void inline fastprint(int v) {
if(obuffer_offset > BS - 11) {
flush();
}
memcpy(obuffer + obuffer_offset, rd[v], rl[v]);
obuffer_offset += rl[v];
}
using namespace std;
int ar[1000001][101];
int struc[2000001][101];
int solnArray[101];
long long modpow(long long b, int e, int mod);
void moveAllElts(int *ar1,int *ar2)
{
	for(int i=1;i<=100;i++)
	ar2[i]=ar1[i];
}
void addRes(int *ar1,int *ar2,int *ar3)
{
	if(ar1==NULL)
	moveAllElts(ar2,ar3);
	else if(ar2==NULL)
	moveAllElts(ar1,ar3);
	else
	{
		for(int i=1;i<=100;i++)
			ar3[i]=ar2[i]+ar1[i];
	}
}
int mid(int start,int end)
{
	int mid1=(start+end)/2;
	return mid1;
}
void mulMod(int struc[][101] , int  structure_start,int structure_end,int query_start,int query_end,int index)
{
	int midle=mid(structure_start,structure_end);
	if(query_start <=structure_start && query_end>=structure_end)
			addRes(struc[index],solnArray,solnArray);
		//return struc[index];

	else
	{
		if(query_end<=midle)
			mulMod(struc, structure_start, midle, query_start,query_end ,2*index);
		else if(query_start>midle)
			mulMod(struc, midle+1,structure_end , query_start, query_end , 2*index+1);
		else
		{
			mulMod(struc,structure_start,midle,query_start,query_end,2*index);
			mulMod(struc,midle+1,structure_end,query_start,query_end,2*index+1);
		}
	
	}
	/*if(query_start>structure_end || query_end<structure_start)
		return 0;
	int midle=mid(structure_start,structure_end);
	return (mulMod(struc,structure_start,midle,query_start,query_end,2*index)*mulMod(struc,midle+1,structure_end,query_start,query_end,2*index+1))%DEF_MOD;
	*/
}
void getMul(int struc[][101],int n,int query_left,int query_right)
{
	 mulMod(struc,0,n-1,query_left,query_right,1);
}
int *buildSegTreeFunc(int ar[][101],int structure_start,int structure_end,int struc[][101],int struct_index)
{
	if(structure_start == structure_end)
	{
		moveAllElts(ar[structure_start],struc[struct_index]);
		//struc [struct_index] = ar[ structure_start];
		return ar[ structure_start];
	}
	int midle=mid(structure_start,structure_end);
	addRes(buildSegTreeFunc(ar,structure_start , midle , struc , 2*struct_index) , buildSegTreeFunc(ar, midle+1,structure_end , struc , 2*struct_index+1),struc[struct_index]);
	return struc[struct_index];
}
/*int * buildSegTree(long long int ar[],long long int n)
{
	long long int logn = (int)(ceil(log2(n))); 
    long long int max_size = 2*(int)pow(2, logn) - 1;
    long long *struc= new long long [max_size];     
    buildSegTreeFunc(ar,0,n-1,struc,1);
    for(int i=0;i<max_size;i++)
    	cout<<struc[i]<<" ";
    	cout<<endl;
	return struc;
}*/
int main()
{
	int n;
	n=fastread();
	int ar1[n];
	
	for(int i=0;i<n;i++)
	{
		int t;
		t=fastread();
		ar[i][t]=1;
		ar1[i]=t;
	}
//	for(int i=0;i<n;i++)
//	cout<<ar[i]<<" ";	
	buildSegTreeFunc(ar,0,n-1,struc,1);
	int t;
	
	t=fastread();
	for(int i=0;i<t;i++)
	{
		int  l,r,MOD;
		l=fastread();
		r=fastread();
		MOD=fastread();
		long long res=1;
		if(r-l <= 16)
		{
			for(int i=l;i<=r;i++)
			{
				res=(res*ar1[i-1])%MOD;
			}
			
		}
		
		else
		{
			getMul(struc ,n, l-1 , r-1);
		//	for(int i=1; i<=100; i++)
		//		cout<<solnArray[i]<<endl;
			for(int i=1;i<=100;i++)
			{
				long long powR=modpow(i,solnArray[i],MOD);
				res= (res*powR)%MOD;
			}
		
		}	
		printf("%lld\n",res);
		for(int i=1; i<=100; i++) solnArray[i] = 0;
	}
	flush();
	return 0;
}
long long modpow(long long b, int e, int mod)
{
    long long reslt = 1;
    while(e)
    {
        if(e & 1)
        {
            reslt = (reslt * b) % mod;
        }
        e >>= 1;
        b = (b * b) % mod;
    }
    return reslt;
}

