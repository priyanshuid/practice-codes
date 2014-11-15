#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#define ll long long
#define MOD 1000000007
using namespace std;

ll exp(ll a, ll b){
    if(b==0)
        return 1;
    else if(b==1)
        return a;
    else {
        ll temp =exp(a, b/2)%MOD;
        if(b%2==0)return (temp*temp)%MOD;
        else return ((temp*temp)%MOD * a)%MOD;
    }
}
int main(){
    int n;
    cin>>n;
    if(n<13)    {cout<<0<<endl;continue;}
    if(n== 13)  {cout<<1<<endl;continue;}
    n = n-13;
    if(n%2 !=0)
        n--;
    n=n/2;
    ll ans = exp(7, n);
    cout<<ans<<endl;
    return 0;
}
