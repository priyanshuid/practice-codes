#include <iostream>
#include <stdio.h>
#include <math.h>
#define NEG_INF -1000000009
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int ar[n];
    int maxm=NEG_INF;
    for(int i=0;i<n;i++)
    {
        scanf("%d", &ar[i]);
        if(ar[i]>maxm)
            maxm=ar[i];
    }
    if(k==0)
    {
        for(int i=0;i<n;i++)
            printf("%d ", ar[i]);
        cout<<endl;
    }
    else
    {
        int maxm_f=NEG_INF;
        int maxm_s=NEG_INF;
        int ar1[n];
        for(int i=0;i<n;i++)
        {
            ar1[i]=maxm-ar[i];
            if(ar1[i]>maxm_f)
                maxm_f=ar1[i];
        }
        int ar2[n];
        for(int i=0;i<n;i++)
        {
            ar2[i]=maxm_f-ar1[i];
            if(ar2[i]>maxm_s)
                maxm_s=ar2[i];
        }
        if(k%2!=0)
        {
            for(int i=0;i<n;i++)
                printf("%d ", ar1[i]);
        }
        else
        {
            for(int i=0;i<n;i++)
                printf("%d ", ar2[i]);
        }
    }
    return 0;
}
