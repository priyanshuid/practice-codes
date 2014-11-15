#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    string str1;
    getline(cin, str1);
    for(int t1=0;t1<t;t1++){
        string str;
        string bb;
        getline(cin, bb);
        getline(cin, str);
        str=str+'&';
        int index;
        int flag=0;
        for(int i=0;i<str.length();i++){
            if(str.at(i)=='=')
            {
                index=3;
                break;
            }else if(str.at(i)== ' ') flag=1;

            if(flag==1){
                if(str.at(i)>='a' && str.at(i)<='z'){
                    index= 2;
                    break;
                }
            }else if(str.at(i)>='a' && str.at(i)<='z'){
                index=1;
                break;
            }
        }
        int n1=0, n2=0, n3=0;
        if(index==2){
            int ind=0;
            while(str.at(ind)!= ' '){
                n1=n1*10 + str.at(ind)-'0';
                ind++;
            }
            while(str.at(ind)!='='){
                ind++;
            }
            ind++;
            ind++;
            while(str.at(ind)!='&'){
                n3= n3*10+str.at(ind)-'0';
                ind++;
            }

            cout<<n1<<" + "<<n3-n1<<" = "<<n3<<endl;
        }else if(index==3){
            int ind=0;
            while(str.at(ind)!= ' '){
                n1=n1*10+str.at(ind)-'0';
                ind++;
            }
            ind++;
            ind++;
            ind++;
            while(str.at(ind)!= ' '){
                n2= n2*10+str.at(ind)-'0';
                ind++;
            }
            cout<<n1<<" + "<<n2<<" = "<<n1+n2<<endl;
        }else {
            int ind=0;
            while(str.at(ind)!=' '){
                ind++;
            }
            ind++;
            ind++;
            ind++;
            while(str.at(ind)!= ' '){
                n2= n2*10 + str.at(ind)-'0';
                ind++;
            }
            ind++;
            ind++;
            ind++;
            while(str.at(ind)!='&'){
                n3=n3*10+str.at(ind)-'0';
                ind++;
            }
            cout<<n3-n2<<" + "<<n2<<" = "<<n3<<endl;
        }

    }
    return 0;
}
