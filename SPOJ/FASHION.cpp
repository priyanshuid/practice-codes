#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
int main(){

    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++){
        int n;
        cin>>n;
        int men[n];
        int women[n];
        for(int i=0;i<n;i++)    cin>>men[i];
        for(int j=0;j<n;j++)    cin>>women[j];

        sort(men, men+n);
        sort(women, women+n);
        ll ans=0;
        for(int i=0;i<n;i++){
            ans += men[i]*women[i];
        }
        cout<<ans<<endl;
    }
}
