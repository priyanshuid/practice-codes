#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int main(){
    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        long long n;
        cin>>n;
        long long ans= 192 + (n-1)*250;
        cout<<ans<<endl;
    }
    return 0;
}
