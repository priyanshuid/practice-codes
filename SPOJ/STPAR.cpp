#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n!=0){
            int ar[n];
            stack <int> S;
            for(int i=0;i<n;i++){
                scanf("%d",&ar[i]);}
            vector <int> soln;
            int i=0;
            int g=1;
            while(i != n){
                if(ar[i]==g){
                    soln.push_back(ar[i]);
                    g++;
                    i++;
                }else if(!S.empty() && S.top()==g){
                    soln.push_back(S.top());
                    g++;
                    S.pop();
                }else {
                    S.push(ar[i]);
                    i++;
                }
            }
            while(!S.empty()){
                soln.push_back(S.top());
                S.pop();
            }
            int flag2=0;
            for(int j=1;j!=soln.size();j++){
                if(soln[j]!=soln[j-1]+1){
                    flag2=1;
                    break;
                }
            }
            if(flag2==0)    cout<< "yes"<<endl;
            else cout<<"no"<<endl;
            cin>>n;
    }
    return 0;
}
