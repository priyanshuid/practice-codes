#include <iostream>
#include <stdio.h>
#include <math.h>
#include <memory.h>
#define MOD 1000000007
using namespace std;
int table[1000005];
void func()
{
    table[1]=1;
    table[2]=2;
    for(int i=3;i<=1000000;i++)
        table[i]=(table[i-1]+table[i-2])%MOD;
}
int main()
{
    int t;
    cin>>t;
    memset(table, 0 , sizeof(table));
    func();
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        cout<<table[n]<<endl;
    }
    return 0;
}
