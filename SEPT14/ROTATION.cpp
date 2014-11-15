#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
int main(){

   int n,m;
   cin>>n>>m;
   int ar[n+1];
   for(int i=1;i<=n;i++) scanf("%d", &ar[i]);
   int init_pos=1;
   char a;
   int pos;
   for(int i=0;i<m;i++){
        cin>>a>>pos;
        if(a == 'R'){
            if(pos + init_pos <= n){
                cout<< ar[init_pos+pos-1]<<endl;
            }else {
                cout<<ar[(init_pos + pos-1)%n]<<endl;
            }
        }else if(a == 'A'){
            if(init_pos+ pos <=n){
                init_pos += pos;
            }else init_pos = (init_pos+pos)%n;
        }else
        {
            if(init_pos - pos >=1){
                init_pos -=pos;
            }else init_pos = init_pos-pos +n;
        }
   }
    return 0;
}
