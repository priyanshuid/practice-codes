#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++){
        string str;
        cin>>str;
        int flag=1;
        for(int i=0;i<str.length();i++){
            if(str.at(i) !='9'){
                flag=0;
                break;
            }
        }
        if(flag==1){
            cout<<1;
            for(int i=0;i<str.length()-1;i++)
                cout<<0;
            cout<<1;
            if(t1!=t-1) cout<<endl;
            continue;
        }else{
            int flag1=0, flag2=0, flag3=0;
            int n=str.length();
            for(int i=str.length()/2-1;i>=0;i--){
                if(str.at(i) < str.at(n-1-i)){
                    flag1=1;
                    break;
                }else if(str.at(i)!=str.at(n-1-i))
                    flag2=1;
                else{
                    flag3=1;
                }
            }
            int index;
            if(flag1==1 || flag2==0){
                if(str.length()%2==0) index= str.length()/2-1;
                else index= str.length()/2;
                int ind;
                for(ind=index;ind>=0;ind--){
                    if(str.at(ind)=='9'){
                        str.at(ind)='0';
                    }else break;
                }
                str.at(ind)= str.at(ind)+1;
                for(int i=0;i< str.length()/2;i++) str.at(n-i-1)= str.at(i);
                cout<< str;
                if(t1!=t-1)cout<<endl;
            }else {
                for(int i=0;i< str.length()/2;i++) str.at(n-i-1)= str.at(i);
                cout<<str;
                if(t1!=t-1) cout<<endl;
            }
        }
    }
    return 0;
}
