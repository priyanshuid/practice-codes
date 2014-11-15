#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++){
        long long k;
        cin>>k;
        long long sum=0;
        for(int i=0;i<k;i++)    {
            long long a;
            cin>>a;
          //  if(sum > k)
            sum = (sum%k + a%k)%k;
           // else sum = sum+a;

        }
        if(sum%k==0)    cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
