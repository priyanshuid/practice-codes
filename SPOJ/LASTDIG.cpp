#include <iostream>
#include <stdio.h>
#include <math.h>
#define ll long long
using namespace std;
ll powLast(ll a, ll b){
    if(b==0)    return 1;
    if(b==1)    return (a%10);
    else {
        ll temp= powLast(a, b/2)%10;
        if(b%2==0)      return (temp*temp)%10;
        else return (temp*temp*a)%10;
    }
}
int main(){
    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++){
        ll a, b;
        cin>>a>>b;
        cout<<powLast(a, b)<<endl;
    }
    return 0;
}