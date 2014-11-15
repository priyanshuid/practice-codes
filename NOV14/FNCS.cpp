#include <bits/stdc++.h>
using namespace std;
int N;
long long BIT[100005];
void update(int i, long long x){
    while(i<=N){
        BIT[i]+=x;
        i += (i&-i);
    }
}
long long read(int i){
    int sum=0;
    while(i>0){
        sum+=BIT[i];
        i -= (i&-i);
    }
    return sum;
}
long long rangeRead(int a, int b){
    return read(b) - read(a-1);
}

int main(){
    int n;
    scanf("%d", &n);
    N=n;
    for(int i=1;i<=n;i++){
        long long a;
        scanf("%lld", &a);
        update(i,a);
    }
    vector <pair <int, int> > functions[n+1];
    for(int i=1;i<=n;i++){
        int a, int b;
        fucntions[i].push_back(pair <int, int>(a, b));
    }
    int Q;
    scanf("%d", &Q);

    for(int i=1;i<Q;i++){

    }
}
