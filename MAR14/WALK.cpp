#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int j=0;j<t;j++)
    {
        int n;
        cin>>n;
        long long max_val=0;
        long long initial=-1;
        for(int i=0;i<n;i++)
        {
            long long k;
            cin>>k;
            if(i==0)
            {
                max_val=k;
                initial=k;
            }
            else
            {
                if(k>max_val)
                {
                    initial+=k-max_val;
                    max_val=k;
                }
            }
            max_val--;
        }
        cout<<initial<<endl;
    }
    return 0;
}
