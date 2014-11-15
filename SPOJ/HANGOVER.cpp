#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int main(){
    float n;
    cin>> n;
    while(n > 0.00){
        float sum=0;
        int c = 2;
        while(sum <= n){
            sum += (float)1/c;
            c++;
        }
        cout<<c-2<<" card(s)"<<endl;
        cin>>n;
    }
    return 0;
}
