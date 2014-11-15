#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int n,q;
	cin>>n>>q;
	vector<vector< int > > ar ;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			ar[i][j]=0;
	}
	for(int i=0;i<q;i++)
	{
		string s;
		int k,v;
		cin>>s>>k>>v;
		if(s=="RowAdd")
			{
			for(int b=0;b<n;b++)
			ar[k-1][b]+=v;
			}
		else if(s=="ColAdd")
		{
			for(int b=0;b<n;b++)
			ar[b][k-1]+=v;
		}
	}
	int max=ar[0][0];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(ar[i][j]>max)
			max=ar[i][j];
		}
	}
	cout<<max<<endl;
	return 0;
}
