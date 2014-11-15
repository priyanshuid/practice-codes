#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++){
        long long n;
        cin>>n;
        long long k= -1 + (long long)sqrt(n+1);
        cout<<"Case "<<t1+1<<": "<<k<<endl;
    }
    return 0;
}
