#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector <int> ar;
    int ansss=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        ansss+=a;
        ar.push_back(-a);
    }
    if(n==1){
        cout<<fabs(ar[0]);
        exit(0);
    }
    int flag=0;
    for(int i=0;i<n;i++){
        if(ar[i]>0){
            flag=1;
        }
    }
    if(flag==0){
        cout<<ansss;
        exit(0);
    }
    int index1=-1;
    int sum=0;
    int temp_sum=0;
    for(int i=0;i<n-1;i++){
        temp_sum=temp_sum+ar[i];
        if(sum<temp_sum)
        {
            sum= sum+ar[i];
            index1=i;
        }

    }
    int index2=-1;
    vector <int> rev_ar;
    for(int i=n-1;i>=0;i--){
        rev_ar.push_back(ar[i]);
    }
    sum=0;
    temp_sum=0;
    for(int i=0;i<n-1-index1;i++){
        temp_sum=temp_sum+rev_ar[i];
        if(sum<temp_sum)
        {
            sum= sum+rev_ar[i];
            index2=i;
        }
    }
    index2 = n-1-index2;
  //  cout<<index1<<" "<<index2<<endl;
    int ans=0;
    if(index1 < index2){
        for(int i=0;i<=index1;i++){
            ans+= ar[i];
          //  cout<<i<<endl;
        }
        for(int i=index1+1;i<index2;i++){
            ans-=ar[i];
           // cout<<i<<endl;
        }
        for(int i=index2;i<=n-1;i++){
            ans+=ar[i];
            //cout<<i<<endl;
        }
    }

    else{
        for(int i=0;i<index2;i++){
            ans+=ar[i];
        }
        for(int i=index2;i<=index1;i++){
            ans+=ar[i];
        }
        for(int i=index1+1;i<=n-1;i++){
            ans+=ar[i];
        }
    }
    cout<<ans;
    return 0;
}
