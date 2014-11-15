#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++)
    {
        int n;
        cin>>n;
        int ar[n][2];
        for(int i=0;i<n;i++)
            cin>>ar[i][0]>>ar[i][1];
        if(n==1)
        {
            cout<<ar[0][0]<<endl;
            continue;
        }
        int sum1=0,sum2=0;
        for(int i=0;i<n;i++)
        {
            sum1+=ar[i][0];
            sum2+=ar[i][1];
        }
        cout<<sum1-sum2<<endl;
    }
    return 0;
}
