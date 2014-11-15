#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
string algo(string vts[],int m,int n);
string lexico(string ar[],int k);
int listSearch(string list[], const int SIZE, string name);
int main()
{
	int n,m;
	cin>>n>>m;
	string country[n],name[n],nm_cpy[n];
	string vts[m];
	for(int i=0;i<n;i++)
	{
		cin>>name[i];
		cin>>country[i];
		nm_cpy[i]=name[i]+("-"+country[i]);
	}
	string *sbeg=&nm_cpy[0],*seend=&nm_cpy[n];
	sort(sbeg,seend);
	for(int i=0;i<m ;i++)
		cin>>vts[i];
	string *vtd_cntry=new string[m];
	for(int i=0;i<m;i++)
	{
		int pos=listSearch(nm_cpy,n,vts[i]);
		vtd_cntry[i]=nm_cpy[pos].substr(nm_cpy[pos].find("-")+1);
	}
	string *beg=&vts[0],*end=&vts[m];
	string *beg1=&vtd_cntry[0],*end1=&vtd_cntry[m];
	sort(beg,end);
	sort(beg1,end1);
	string name1=algo(vts,m,n);
	string cntry1=algo(vtd_cntry,m,n);
	cout<<cntry1<<endl<<name1;
	return 0;
}
string lexico(string ar[],int k)
{
	string min_string=ar[0];
	for(int i=1;i<= k;i++)
	{
	/*	int lm =min_string.length();
		int le =ar[i].length();
		if(le<=lm)
		{
	
			for(int j=0;j<le && flg!=1;j++)
			{
				if(((int)(ar[i].at(j)))<((int)min_string.at(j)))
				{
					min_string=ar[i];
					flg=1;
					break;
				}	
			}
		}
		else
		{
			int flg=0;
			for(int j=0;j<lm && flg!=1;j++)
			{
				if(((int)(ar[i].at(j)))<((int)min_string.at(j)))
				{
					min_string=ar[i];
					flg=1;
					break;
				}		
			} */
		if(ar[i]<min_string)
		min_string=ar[i];
		}	
	
	return min_string;
}
int listSearch(string list[], const int SIZE, string name)
{
	int first = 0,last = SIZE - 1,middle,position = -1;
	bool found = false;
	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (list[middle].substr(0,list[middle].find("-")) == name)
		{
			found = true;
			position = middle;
		}
		else if ((list[middle].substr(0,list[middle].find("-")) > name))
			last = middle - 1;
		else
			first = middle + 1;	
	}

	return position;
}
string algo(string vts[],int m,int n)
{
	int *count=new int[n];
	int k=0;
	count[0]=1;
	for(int i=1;i< m ;i++)
	{
		if(vts[i]==vts[i-1])
		count[k]+=1;
		else
		{
			k++;
			count[k]=1;
		}
	}
	int max_count=count[0];
	for(int i=0;i<=k;i++)
	{
		if(count[i] >= max_count)
		max_count=count[i];
	}
	string *ar2=new string[m];
	int flg=-1,sum=0;
	for(int i=0;i<=k;i++)
	{
		sum=sum+count[i];
		if(count[i]==max_count)
		ar2[++flg]=vts[sum-1];
	}
	string name1=lexico(ar2,flg);
	return name1;
}
