#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <math.h>
#include <time.h>
#include <map>
#include <unistd.h>
#include <csignal>
#include <time.h>
#include <signal.h>
#include <stdlib.h>
#define unsigned long long ull
using namespace std;
//std::sig_atomic_t volatile done = 0;

//void game_over(int) { done = 1; }
int main()
{
	int m;
	scanf("%d",&m);
	if(m>=3)
	{
		int ar[m];
		for(int i=0;i<m;i++)
			scanf("%d",&ar[i]);
		int *st=&ar[0],*en=&ar[m];
		sort(st,en);
		int count=2;
		vector <int> list;
		list.push_back(ar[0]);
		list.push_back(ar[1]);
		//std::signal(SIGALRM, game_over);
    	//alarm(1);
		
         for(int i=2;i<5000;i++)
         {
         	int flag=1;
			for(int j=0;j<list.size();j++)
         	{
         		for(int k=j+1;k<list.size();k++)
         		{
         			
         				if(ar[i]-list[k]==list[k]-list[j])
         				{
         					flag=0;
         				}
         			
         		}
         	}
         	if(flag==1)
         	{
         		list.push_back(ar[i]);
         		count++;
         	}
        }
		if(count>2)
		{
			printf("%d\n",count);
			for(int i=0;i<count;i++)
			printf("%d ",list[i]);
		}
}
	else 
	cout<<0;
	return 0;
}


