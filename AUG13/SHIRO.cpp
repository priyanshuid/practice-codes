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
float prob[10010][110];
int main()
{
	int ar[110];
    float p[110]; 
    int t;
    scanf("%d",&t);
    for(int t1=0;t1<t;t1++)
	{
    	int n;
        memset(prob,0,sizeof(prob));
    	scanf("%d",&n);
    	int sum=0;
        for(int i=1;i<=n;i++)
		{
            scanf("%d",&ar[i]);
        	sum+=ar[i];
        }
        int pi;
        ar[0]=0;
        p[0]=0;
		for(int i=1;i<=n;i++)
		{
            scanf("%d",&pi);
            p[i]=pi/(float)100;
        }
      //  for(int i=0;i<=n;i++)
       // cout<<p[i]<<endl;
        
        for(int i=0;i<=sum;i++)
        	prob[i][0]=prob[i][1]=0.0;
        prob[0][1]=(float)1-p[1];
        prob[ar[1]][1]=p[1];
        for(int j=2;j<=n;j++)
		{
			for(int i=0;i<=sum;i++)
			{               
                if(i<ar[j])
                    prob[i][j]=prob[i][j-1]*(1-p[j]);
                else
                    prob[i][j]=prob[i][j-1]*(1-p[j]) + prob[i-ar[j]][j-1]*p[j];
                                         
            }
        }
        for(int i=0;i<sum;i++)
        {
        	for(int j=0;j<=n;j++)
        		cout<<prob[i][j]<<"       ";
        	cout<<endl;
        }
        	float ans=0.0;
			for(int i=(sum+1)/2;i<=sum;i++)
                ans+=prob[i][n];
            std::cout.setf( std::ios::fixed, std:: ios::floatfield ); 
			std::cout.precision(6); 
			cout<<ans<<endl;  
    }
	return 0;
}
