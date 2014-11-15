#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
#define MOD 1000000
using namespace std;
bool ar[1000005];
int main()
{
    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++)
    {
        int n;
        scanf("%d",&n);
        int a,b,c,d;
        scanf("%d %d %d %d",&a, &b, &c, &d);
        int sum1=0;
        memset(ar, 0 , sizeof(ar));
        long long prev_val=d;
        ar[d]=1;
        for(int i=1;i<n;i++)
        {
            int val=(prev_val*a*prev_val+b*prev_val + c)%MOD;
            //cout<<val<<endl;
            if(ar[val]==0)
                ar[val]=1;
            else    ar[val]=0;
            prev_val=val;
        }
        int sum2=0;
        int count=0;
        for(int i=1000000;i>=0;i--)
        {
            if(ar[i]==1)
            {
                if(count==0)
                    {
                        sum1+=i;
                        ar[i]=0;
                        count=1;
                    }
                else
                {
                    sum2+=i;
                    ar[i]=0;
                    count=0;
                }
            }
        }
    //    cout<<sum1<<" "<<sum2<<endl;
        int ans=(sum1>sum2) ?(sum1-sum2 ): (sum2-sum1);
        printf("%d\n",ans);
    }
    return 0;
}
