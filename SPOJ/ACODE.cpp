#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
char ar[10000];
int value(int i, int n)
{
    if(i>n)
        return 0;
    if(i==n-1 || i==n)
        return 1;
    else
    {
        if(ar[i]<=2)
            return (value(i+1,n)+ value(i+2,n));
        else return value(i+1,n);
    }
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        scanf("%s", ar);
        cout<<ar;
        cout<<value(0,n)<<endl;
    }
}
