#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007
using namespace std;
long long multiply(long long base,long long exp)
{
    if(exp==0)
        return 1;
    else if(exp==1)
        return base;
    else
    {
        if(exp%2==0)
            return multiply((base*base)%MOD , exp/2);
        else
            return (base*multiply(base*base%MOD, exp/2))%MOD;
    }
}
int main()
{
    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++)
    {
        int base,exp;
        cin>>base>>exp;
        long long val=multiply(base,exp);
        cout<<val<<endl;
    }
    return 0;
}
