#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++){
        int n;
        cin>>n;
        int k=1;
        while( n-k> k+1){
            n=n-k;
            k++;
        }
        n=n-k;
        if(k%2!=0)
            cout<< k+2-n<<"/"<<k<<endl;
        else cout<<n<<"/"<<k<<endl;
    }
}
