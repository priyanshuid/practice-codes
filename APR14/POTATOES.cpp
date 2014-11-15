#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
bool prime[3000];
void generate()
{
    for(int i=0;i<=3000;i++)
        prime[i]=1;
    for(int i=2;i<sqrt(3000)+1;i++)
    {
        for(int j=i*i;j<3000;j=j+i)
        {
            prime[j]=0;
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    generate();
    for(int i=0;i<t;i++)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        int sum=a+b+1;
        if(prime[sum]==1)
        {
            printf("%d\n", 1);
            continue;
        }
        else
        {
            while(prime[sum]!=1)
                sum++;
            printf("%d\n" , sum-a-b);
        }
    }
    return 0;
}
