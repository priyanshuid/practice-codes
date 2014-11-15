#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    while(n!=-1){
        if(n==1)cout<<"Y"<<endl;
        else {
            int flag=0;
            for(int i=1;i<=sqrt(n);i++){
                if(3*i*(i+1)+1-n ==0){
                    flag=1;
                    break;
                }
            }
            if(flag==1)cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }
        cin>>n;
    }
    return 0;
}
