#include <iostream>
#include <stdio.h>
#include <math.h>
#define MOD 1000000009
using namespace std;
long long fst(long long a , long long b)
{
    if(b==0)
        return 1;
    else if(b==1)
        return a;
    else
    {
        if(b%2==0)
            return fst((a%MOD*a%MOD)%MOD, b/2);
        else return (a%MOD*(fst((a%MOD*a%MOD)%MOD, b/2))%MOD)%MOD;
    }
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        long long n;
        cin>>n;
        long long ans1=fst((long long)2, n);
        cout<<fst((long long)2, ans1)<<endl;
    }
    return 0;
}
