
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MAXN = 500020;
ll tree[MAXN], A[MAXN];
ll read(int idx){
ll sum = 0;
 while (idx > 0){
  sum += tree[idx];
  idx -= (idx & -idx);
 }
 return sum;
}

void update(int idx ,ll val){
 while (idx <= MAXN){
  tree[idx] += val;
  idx += (idx & -idx);
 }
}
int main() {
   ll N,t,K;
   cin >> t;
   for(ll t1=0;t1<t;t1++){
   cin >> N >> K;
      memset(tree, 0, sizeof(tree));
      for(ll i = 0; i < N; ++i) {
         scanf("%lld",&A[i]);
      }
      ll inv_count = 0;
      for(ll i = N - 1; i >= 0; --i) {
         ll x = read(A[i] - 1);
         inv_count += x;
         update(A[i], 1);
      }
      if(K>=inv_count){
      sort(A, A+N);
      int flag=0;
      for(int kk=0;kk<N-1;kk++){
        if(A[kk]==A[kk+1]){
            flag=1;
            break;
        }
      }
      if(flag==1){
        printf("Case %lld: 0\n",t1+1);
        continue;
      }
       if((K-inv_count)%2)
        printf("Case %lld: 1\n",t1+1);
        else
        printf("Case %lld: 0\n",t1+1);
      }
      else{
      printf("Case %lld: %lld\n",t1+1,inv_count-K);
      }
   }
   return 0;
}
