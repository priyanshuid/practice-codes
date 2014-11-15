#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
typedef unsigned long long int ull;
using namespace std;
struct tuple
{
	ull b,l;
	tuple()
	{
		b=0;
		l=0;
	}
};
struct compareTuple
{
    inline bool operator() (const tuple& struct1, const tuple& struct2)
    {
        return (struct1.l <= struct2.l);
    }
};
int main()
{
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++)
	{
		int n;
		cin>>n;
		tuple ar[n];
		for(int i=0;i<n;i++)
			scanf("%llu %llu",&ar[i].b,&ar[i].l);
		tuple *start,*end;
		start =&ar[0];
		end =&ar[n];
		ull sum=0,count=0;
		sort(start,end,compareTuple());
		set <ull> s1;
		set<ull>::iterator it;
		for(int i=0;i<n;i++)
		{
			if(s1.find(ar[i].b)!=s1.end())
			sum+=count*ar[i].l;
			else
			{
				count++;
				sum+=count*ar[i].l;
				s1.insert(ar[i].b);		
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

