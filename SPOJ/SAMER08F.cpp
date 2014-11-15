#include <iostream>
#include <stdio.h>
#include <math.h>
#define ll long long
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n!=0){
        int i=1;
        ll sum=0;
        ll sq= n*n;
        while(i*i <= sq){
            sum += (i*i);
            i++;
        }
        cout<<sum<<endl;
        cin>>n;
    }
    return 0;
}
