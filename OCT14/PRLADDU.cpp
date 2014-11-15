#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++){
        int n;
        cin>>n;
        int ar[n+1];
        for(int i=1;i<=n;i++)    scanf("%d", &ar[i]);
        long long value=0;
        for(int i=1;i<n;i++){
                if(ar[i]<0) value= value - ar[i];
                else value= value + ar[i];
                ar[i+1] += ar[i];
        }
        if(value<0)cout<< -value<<endl;
        else cout<<value<<endl;
    }
    return 0;
}
