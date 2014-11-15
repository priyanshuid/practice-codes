/**
Segmented sieve is used to generate rime numbers between two ranges.
Conventional method would use time - O(nsqrt(n)),
however sieve uses O(nlogn))
Range where we want to generate prime numbers (a, b):
We first generate prime numbers upto sqrt(b) numbers.
We then use these primes to generate the prime numbers from a to b.
**/
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
//these two arrays are used to generate all primes till sqrt(b)
// we take these arrays as global variables
bool primeCheckTillSqrt[500000];
int primeTillSqrt[100000];
//function to generate the prime numbers till sqrt of the larger numbers of the two
void seive(int n, int &top){
    //we first assume that all numbers are primes
    // and then go on to prune the numbers that are multiples of the primes
    for(int i=1;i<=n;i++){
        primeCheckTillSqrt[i]=1;
    }
    primeCheckTillSqrt[1]=0;
    //you might think that these two arrays should make the
    //running time equal to c*n*sqrt(n)
    //but amortized analysis gives the required time.
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
//function to generate primes between a and b.
// we have generated primes till sqrt(b)
// and we use those primes to prune numbers between a and b.
int segmentCheck(int prime[], int a, int b){
    int top1=0;
    int primeCheck[b-a+1];
    int top;
    if(a==2) a=1;
    if(a%2 != 0 && a!= 1) a--;
    seive((int)sqrt(b), top);
    //set all numbers as primes
    for(int i=1;i<=b-a;i++){
        primeCheck[i]=1;
    }
    // go till sqrt of the second number and prune the corresponding entry from the segment
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
    //store prime numbers in array[prime]
    for(int i=0;i<=b-a;i++){
        if(primeCheck[i]==1){
            prime[top1++]=i+a;
        }
    }
    top1--;
    return top1;
}
//test run
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
