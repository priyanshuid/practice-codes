#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <vector>
#define ll long long
#define MOD 1000000007
#define MAX_LIM 100005
char ar[100005];
using namespace std;
ll value(char *ar, int n){
    ll val= 1;
    for(int i=0;i<n;i++){
        if(ar[i]=='l'){
            if(i%2 == 0)
                    val = (val*2)%MOD;
            else val = ((val*2)%MOD -1)%MOD;

        }else{
                if(i%2==0)
                    val = ((val*2)%MOD +2)%MOD;
                else val = ((val*2)%MOD +1)%MOD;
        }
    }
    return val;
}
int main(){
    int t;
    scanf("%d", &t);
    for(int t1=0;t1<t;t1++){

        scanf("%s", ar);
        ll ans=value(ar, strlen(ar));
        cout<<ans<<endl;
    }
    return 0;
}
