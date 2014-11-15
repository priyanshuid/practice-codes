#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int tracker=0;
    for(int i=0;i<n;i++){
        int shifted = 1<<ar[i];
        tracker ^= shifted;
    }
    for(int i=0;i< n;i++){
        int shifted = 1<<ar[i];

        if((shifted & tracker) ==0){
            cout<<ar[i]<<endl;
            tracker ^=shifted;
        }
    }
    return 0;
}
