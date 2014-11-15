#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
for(int i=0;i<t;i++){
    int n,k,count=0;
    cin>>n>>k;
    for(int j=0;j<n;j++){
        int a;
        cin>>a;
        if(a>=k)count++;
    }
    cout<<count<<endl;
}
return 0;
}
