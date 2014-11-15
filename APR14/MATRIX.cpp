#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++)
    {
        int n;
        scanf("%d",&n);
        long long sum=0;
        for(int i=1;i<=n/2;i++)
        {
            int val=i*(n-i);
            int mul_fact;
            if(i==n-i)
                mul_fact=1;
            else mul_fact=2;
            int count=0;
            for(int j=1;j<=sqrt(val);j++)
            {
                if(val%j==0)
                {
                    if(val/j==j)
                        count++;
                    else count+=2;
                }
            }
            sum+=mul_fact*count;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
