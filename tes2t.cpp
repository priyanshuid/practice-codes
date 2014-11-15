#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
 
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define mod 1000000007
#define MAXN 1000010
 
typedef pair<int,int>   PI;
typedef vector<int> VI;
typedef long long int LL;
int main(){
    int t,n,m,i;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        if(n==1 && m==1){
            printf("1\n");
        }
        else if(n<2*m){
            printf("-1\n");
        }
        else{
            for(i=2;i<=2*m;i+=2){
                printf("%d ",i);
            }
            printf("\n");
        }
    }
	return 0;
}
