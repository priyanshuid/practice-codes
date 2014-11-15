#include <bits/stdc++.h>
using namespace std;
int main(){

    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++){
        int n;
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        sort(ar, ar+n);
        cout<<"Case "<<t1+1<<": "<<ar[n-1]+ar[n-2]+ar[n-3]<<endl;
    }
    return 0;
}
