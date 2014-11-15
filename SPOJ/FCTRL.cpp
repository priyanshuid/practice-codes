#include <math.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int main(){

    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++){
        ll n;
        cin>>n;
        int k = 1;
        int total_zeros = 0;
        while( pow(5, k) <= n){
            total_zeros += (n / (int)pow(5, k));
            k++;
        }
        cout<<total_zeros<<endl;
    }
    return 0;
}
