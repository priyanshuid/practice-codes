#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <memory.h>
using namespace std;
bool prime[31700];
int primes[4000];
int top=-1;
void prime_generate()
{
    for(int i=2;i<sqrt(31700)+1;i++)
    {
        if(prime[i]==1)
        {
            for(int j=i*i;j<31700;j=j+i)
                prime[j]=0;
        }
    }
    for(int i=2;i<31700;i++)
    {
        if(prime[i]==1)
            primes[++top]=i;
    }
}
int main()
{
    int t;
    cin>>t;
    memset(prime,1,sizeof(prime));
    prime_generate();
    for(int t1=0;t1<t;t1++)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        int counter=0;
        if(m==1)
            m++;
        for(int i=m;i<=n;i++)
        {
            int val=2;
            int pos=0;
            int flag=1;
            while(val<=sqrt(i))
            {
                if(i%val==0)
                {
                    flag=0;
                    break;
                }
                val=primes[pos++];
            }
            if(flag==1)
                printf("%d\n",i);
        }
    }
    return 0;
}
