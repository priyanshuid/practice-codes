// Count Sort
#include <iostream>
#include <math.h>
#include <memory.h>
#include <stdio.h>
using namespace std;
int main(){
    int n, k;
    cin>>n>>k;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    int pos[k];
    memset(pos, 0, sizeof(pos));
    for(int i=0;i<n;i++)
        pos[ar[i]]++;
    int previous_sum=0;
    for(int i=0;i<k;i++){
        int temp= previous_sum;
        previous_sum+=pos[i];
        pos[i]=temp;
    }
    int out[n];
    for(int i=0;i<n;i++){
        out[pos[ar[i]]]=ar[i];
        pos[ar[i]]++;
        cout<<out[i]<<endl;
    }
}
