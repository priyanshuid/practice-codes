#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;
struct cont
{
	string name;
	string country;
	int count;
};
int partition(cont *ar,int p,int q);
void quicksort(cont *ar,int p,int q);
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	cont ar[n];
	string vts[m];
	for(int i=0;i<n;i++)
		{
			cin>>ar[i].name>>ar[i].country;
			ar[i].count=0;
		}
	for(int i=0;i<m;i++)
		cin>>vts[i];
//	quicksort(ar,0,n-1);
		for(int i=0;i< n;i++)
		cout<<ar[i].name<<ar[i].country<<endl;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(vts[i].compare(ar[j].name)==0)
			{
				ar[j].count+=1;
				break;
			}
		}
	}
	
	int max=ar[0].count;
	for(int i=0;i<n;i++)
	{
		if(ar[i].count>max)
		max=ar[i].count;
	}
	cont *ar2=new cont[5];
	int flg=-1;
	for(int i=0;i<n;i++)
	{
		if(ar[i].count==max)
			ar2[++flg]=ar[i];
	}
	/*			quick sort the resultant array lexicographically to get the name to be printed
				siilarly sort the country names
				the element with the highest value will be the answer	
			*/
	string max_name[10]=ar2[0].name;
	string max_country[10]=ar[0].country;
	for(int i=0;i<flg;i++)
	{
			string c[10]=ar2[i].name;
			if(lexicographical_compare(c,c+10,max_name,max_name+10))
			max_name[0]=ar2[i].name;
	}
	cout<<max_name;			
	return 0;
	
}
int partition(cont *ar,int p,int q)
{

	string x[10]=ar[p].name;
	int i=p;
	for(int j=p+1;j<=q;j++)
	{
		string b[10]=ar[j].name;
		if(b <=x )
		//if(lexicographical_compare(b,b+10,x,x+10))
		{
			i++;
			cont temp=ar[i];
			ar[i]=ar[j];
			ar[j]=temp;
		}
	}
	cont temp=ar[p];
	ar[p]=ar[i];
	ar[i]=temp;
	return i;
}
void quicksort(cont *ar,int p,int q)
{
	int r;
	if(p < q)
	{
		r=partition(ar,p,q);
		quicksort(ar,p,r-1);
		quicksort(ar,r+1,q);
	}
}
