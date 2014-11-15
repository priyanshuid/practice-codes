#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
long long calculate(long long n,long long r)
{
    if(r>n/2)
        r=n-r;
    int i;
    long long ans=1;
    for(i=1;i<=r;i++)
    {
        ans*=n-r+i;
        ans/=i;
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++)
    {
        long long n,k;
        cin>>n>>k;
        n=n-k;
        long long val=calculate(n+k-1,k-1);
        cout<<val<<endl;
    }
    return 0;
}
