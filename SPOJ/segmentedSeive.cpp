#include <iostream>
#include <math.h>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
bool primeCheckTillSqrt[500000];
int primeTillSqrt[100000];
void seive(int n, int &top){
    for(int i=1;i<=n;i++){
        primeCheckTillSqrt[i]=1;
    }
    primeCheckTillSqrt[1]=0;
    primeCheckTillSqrt[2]=1;
    for(int i=2;i<=sqrt(n)+1;i++){
        if(primeCheckTillSqrt[i]==1){
            for(int j=i+i ; j<=n; j= j+i){
                primeCheckTillSqrt[j]=0;
            }
        }
    }
    top=0;
    for(int i=2;i<=n;i++){
        if(primeCheckTillSqrt[i]==1){
            primeTillSqrt[top++]=i;
        }
    }
    top--;
}

int segmentCheck(int prime[], int a, int b){
    int top1=0;
    int primeCheck[b-a+1];
    int top;
    if(a==2) a=1;
    if(a%2 != 0 && a!= 1) a--;
    seive((int)sqrt(b), top);
    for(int i=1;i<=b-a;i++){
        primeCheck[i]=1;
    }
    for(int i=0;i<=top && primeTillSqrt[i]*primeTillSqrt[i]<=b;i++){
        int val= primeTillSqrt[i];
        int j= (a+val-1)/val;
        j=j*val;
        for(j;j<=b;j=j+val){
            if(j>val){
            primeCheck[j-a]=0;}
         //   cout<<j-a<<endl;
        }
    }

    for(int i=0;i<=b-a;i++){
        if(primeCheck[i]==1){
            prime[top1++]=i+a;
        }
    }
    top1--;
    return top1;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        int primes[200000];
        int number = segmentCheck(primes, a, b);
        for(int i=0;i<=number;i++){
            cout<<primes[i]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
