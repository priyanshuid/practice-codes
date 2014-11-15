#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int primes[100];
int top;
bool primeCheck[105];
int answer[10005];
void primeGenerate(){
    top=0;
    for(int i=0;i<101;i++)	primeCheck[i]=1;
    primeCheck[1]=0;
    primeCheck[0]=0;
    for(int j=2;j<=sqrt(101);j++){
      if(primeCheck[j] == 1){
      for(int k=2*j;k<101;k=k+j){
            primeCheck[k]=0;
            }
        }
    }
    primeCheck[1]=1;
  for(int i=0;i<101;i++){	if(primeCheck[i]==1) primes[top++]=i;}
}
void generateAnswer(){

  answer[0]=0;	answer[1]=1; answer[2]=2;
  for(int i=3;i<10005;i++){
    int k=0;
    for(int k=1;k<=sqrt(i);k++){
      if(i%k==0)	answer[i]++;
    }
    answer[i]+=answer[i-1];
  }
}
int main(){
    int n;
    generateAnswer();
   // for(int i=0;i<top;i++)  cout<<primes[i]<<" ";
   // cout<<endl;
  //  for(int i=0;i<10005;i++) cout<<answ
    cin>>n;
    cout<<answer[n]<<endl;
    return 0;
}
