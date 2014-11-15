#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
void input(int ar[], int n){
    for(int i=0;i<n;i++){
        scanf("%d", &ar[i]);
    }
}
int maxm(int ar[], int n){
    int tmax=ar[0];
    for(int i=1; i<n; i++){
        if(tmax<ar[i])  tmax= ar[i];
    }
    return tmax;
}
int main(){
    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++){
        int r, g, b, m;
        cin>>r>>g>>b>>m;
        int rcol[r], gcol[g], bcol[b];
        input(rcol, r);
        input(gcol, g);
        input(bcol, b);
        int maxInThree[3];
        maxInThree[0]=maxm(rcol, r);
        maxInThree[1]=maxm(gcol, g);
        maxInThree[2]=maxm(bcol, b);
        for(int i=0;i<m;i++){
                int globMax=maxInThree[0];
                int index= 0;
                for(int j=1;j<3;j++){
                    if(maxInThree[j]>globMax){
                        globMax=maxInThree[j];
                        index=j;
                    }
                }
                maxInThree[index]=maxInThree[index]/2;
        }
        int maxm1= max(maxInThree[0],max(maxInThree[1],maxInThree[2]));
        cout<<maxm1<<endl;
    }
}
