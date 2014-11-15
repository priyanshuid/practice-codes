#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++){
        long long k, p,q;
        cin>>k>>p>>q;
        long long n= 2*q/(p+k);
        long long a= k - 2*((p-k)/(n-5));
        long long d= (k - a)/2;
        cout<<n<<endl;
        for(int i=0;i<n;i++){
            cout<<a+i*d<<" ";
        }
        cout<<endl;
    }
    return 0;
}
