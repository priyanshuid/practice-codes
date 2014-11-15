#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <math.h>
#include <map>
#define unsigned long long ull
using namespace std;
int func(string a, char &c)
{
	int ar[26];
	for(int i=0;i<26;i++)
		ar[i]=0;
	for(int j=0;j<a.length();j++)
		{	if(a.at(j)>='a' && a.at(j)<='z')
			ar[a.at(j)-97]++; 
		}
	int max1=ar[0];
	int index=0;
	for(int i=0;i<26;i++)
	{
		if(ar[i]>max1)
		{
			max1=ar[i];
			index=i;
		}
	}
	c=(char)(index+97);
	return max1;
}

int main()
{
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++)
	{
		string w;
		//char ar[1000];
		//scanf("%s",&ar);
		//w=ar;
		cin>>w;
		int count=0;
		for(int i=0;i<w.length();i++)
		{
			if(w.at(i)=='#')
				count++;
		}
		int index[count+1],k=-1;
		for(int i=0;i<w.length();i++)
		{
			if(w.at(i)=='#')
				index[++k]=i;
		}
		index[++k]=w.length();
		int max=0;
		string d1="",d2="",d3="",d4="";
		int val1=0,val2=0,val3=0,val4=0;
		char c1,c2,c3,c4;
		for(int i=0;i<count-2;i++)
		{
			if(i==0)
			d1=w.substr(0,index[i]);
			else d1=d1+d2;
			if(i==0)
			d2=w.substr(index[i]+1,index[i+1]-index[i]-1);
			else d2=d3;
			d3=w.substr(index[i+1]+1,index[i+2]-index[i+1]-1);
			d4=w.substr(index[i+2]+1,w.length()-index[i+2]-1);
			int sum=0;
	//		if(i==0)
			val1=func(d1,c1);
	//		else 
	//		{
	//			if(c1==c2)
	//			val1+=val2;
	///			else
	//			{
	//				if(val1<val2)
	//				val1=val2;
	//			}
	//		}
	//		if(i==0)
		val2=func(d2,c2);
	//		else 
		//	{
			//	if(c2==c3)
			//	val2+=val3;
			//	else
			//	{
			//		if(val2<val3)
	//					val2=val3;
			//	}
			//}
			val3=func(d3,c3);
		//	else 
		//	{
		//		if(c3==c4)
		//		val3+=val4;
		//		else
		//		{
		//			if(val3<val4)
		//				val3=val4;
		//		}
		//	}
			val4=func(d4,c4);
	//	cout<<val1<<" "<<val2<<" "<<val3<<" "<<val4<<" "<<endl;
			if(val1!=0 && val2 !=0 && val3!=0 && val4!=0)
				sum+=val1+val2+val3+val4+3;
			
			else
				sum=0;
			if(i==0)
				max=sum;
			else 
			{
				if(sum>max)
				max=sum;
			}
		}
		cout<<max<<endl;	
	}
}

 
