#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <map>
#include <queue>
#include <vector>
#include <list>
#include <string.h>
using namespace std;
class entry
{
	public:
		int start;
		int end;
		int num;
};
entry e[100001];
struct compare
{
	inline bool operator() (const entry &e1,const entry &e2)
	{
		if(e1.num < e2.num)
			return true;
		else if(e1.num== e2.num)
		{
			if(e1. end < e2. end)
				return true;
			else
				return false;
		}
		else
			return false;
	}
};
int main()
{
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++)
	{
		int N,K;
		cin>>N>>K;
		if(N==0)
		{
				cout<<0<<endl;
				continue;
		}
		for(int i=0;i<N;i++)
			scanf("%d %d %d",&e[i].start,&e[i].end,&e[i].num);
		sort(e,e+N,compare());
		//for(int i=0;i<N;i++)
		//cout<<e[i].start<<" "<<e[i].end<<" "<<e[i].num<<endl;
		int count=1;
		int previous_end=e[0].end;
		for(int i=1;i<N;i++)
		{
			if(e[i-1].num!=e[i].num)
				{
					count++;
					previous_end=e[i].end;
				}
			else
			{
					if(previous_end <= e[i].start)
					{
							count++;
							previous_end=e[i].end;
					}		
			}
		}
		printf("%d\n",count);
	}
	return 0;
}

