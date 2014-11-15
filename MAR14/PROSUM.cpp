#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++)
    {
        int n;
        cin>>n;
        int two_till_now=0;
        int n1=0;
        long long val=0;
        long long count=0;
        for(int i=0;i<n;i++)
        {
            int k;
            scanf("%d",&k);
            if(k==1 || k==0)
                continue;
            else
            {
                if(k==2)
                {

                    val+=count-two_till_now;
                    two_till_now++;
                }
                else
                {
                    val+=count;
                }
            }
            count++;
        }
        printf("%lld\n",val);
    }
    return 0;
}
