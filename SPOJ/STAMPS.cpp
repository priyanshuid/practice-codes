#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++){
        int sum,n;
        cin>>sum>>n;
        int ar[n];
        for(int i=0;i<n;i++)
            scanf("%d", &ar[i]);
        sort(ar, ar+n);
        int count=0;
        int tsum=0;
        for(int i=n-1;i>=0;i--){
            tsum+= ar[i];
            count++;
            if(tsum>=sum) break;
        }
        cout<<"Scenario #"<<t1+1<<":"<<endl;
        if(tsum>=sum)
            cout<< count<<endl;
        else cout<<"impossible"<<endl;
    }
}
