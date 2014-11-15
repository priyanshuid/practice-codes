#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <memory.h>
#include <vector>
#include <queue>
#include <math.h>S
using namespace std;
void sieve(bool ar[],int n)
{
    memset(ar,true,sizeof(ar));
    for(int i=2;i<sqrt(n)+1;i++)
    {
        if(ar[i]!=false)
        {
            for(int j=i*i;j<n;j=j+i)
            {
                    ar[j]=false;
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    bool ar[2000000];
    memset(ar , true , sizeof(ar));
    sieve(ar,2000000);
    for(int t1=0;t1<t;t1++)
    {
        int n;
        cin>>n;
        if(ar[n]==1)
            cout<<"PRIME"<<endl;
        else cout<<"NON PRIME"<<endl;
    }
    return 0;
}
