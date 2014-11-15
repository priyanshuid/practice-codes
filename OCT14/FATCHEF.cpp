#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define MOD 1000000009
using namespace std;
struct point{
    char ch;
    int pos;
};
bool compare(const point &p1, const point &p2){
    return p1.pos < p2.pos;
}
int main(){
    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++){
        int m,n;
        cin>>n>>m;
        point ar[m];
        for(int i=0;i<m;i++){
            getchar();
            scanf("%s %d",&ar[i].ch,&ar[i].pos);
            }
        sort(ar, ar+m, compare);
        unsigned long long ans=1LL;
        for(int i=1;i<m;i++){
            if(ar[i].ch != ar[i-1].ch){
                    ans = ans*(ar[i].pos-ar[i-1].pos);
                ans=ans%MOD;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
