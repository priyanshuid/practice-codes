#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++)
	{
		int n,m;
		cin>>n>>m;
		int ar[m][2],flg=-1;
		int count[n];
		for(int i=0;i<n;i++)
		count[i]=1;
		for(int i=0;i<m;i++)
			{
				scanf("%d %d",&ar[i][0],&ar[i][1]);
				count[ar[i][0]]=0;
				count[ar[i][1]]=0;
			}
		for(int i=0;i<m;i++)
		{
			
			if(ar[i][0]!=0)
			{
				vector<int> temp;
				temp.push_back(ar[i][0]);
				temp.push_back(ar[i][1]);
				ar[i][0]=0;
				ar[i][1]=0;
				for(int j=0;j<m;j++)
				{
					if(ar[j][0]!=0)
					{
						for(int k=0;k<temp.size();k++)
						{
							if(temp[k]==ar[j][0])
							{
								temp.push_back(ar[j][1]);
								ar[j][0]=0;
								ar[j][1]=0;
							}
							else if(temp[k]==ar[j][1])
							{
								temp.push_back(ar[j][0]);
								ar[j][0]=0;
								ar[j][1]=0;
							}
						}
					}
				}
				vector<int> ::iterator t1=temp.begin();
				vector<int> ::iterator t2=temp.end();
				sort(t1,t2);
				int cnt=1;
				for(int p=0;p <temp.size()-1; p++)
				{
					if(temp[p+1]!=temp[p])
					cnt++;
				}
				count[++flg]=cnt;
			}
		}
		int sum=0,mul=1;
		for(int x=0;x<n;x++)
		{
			if(count[x]!=0)
			{
				sum++;
				mul=mul*count[x];
			}
		}
		cout<<sum<<" "<<mul<<endl;
	}
}

