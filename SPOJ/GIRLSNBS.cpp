#include <bits/stdc++.h>
using namespace std;
int main(){
    int b,g;
    cin>>b>>g;
    while(b!=-1 && g!=-1){
        if(b<g){
            int temp=b;
            b=g;
            g=temp;
        }
        if(b%(g+1)==0){
            cout<<b/(g+1)<<endl;
        }else{
            cout<<b/(g+1) +1 <<endl;
        }
        cin>>b>>g;
    }
    return 0;
}
