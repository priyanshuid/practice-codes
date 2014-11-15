#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++)
    {
        int n,k,p;
        scanf("%d %d %d", &n, &k, &p);
        int k_cut[k][2];
        int p_cut[2*p+5];
        for(int i=0;i<k;i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            k_cut[i][0]=a;
            k_cut[i][1]=b;
        }
        int c=0;
        for(int i=0;i<p;i++)
        {
            int a,b;
            scanf("%d %d", &a, &b);
            p_cut[c++]=a;
            if(b==n)
                b=0;
            p_cut[c++]=b+1;
        }
        int flag=0;
        for(int i=0;i<c && flag==0;i++)
        {
            for(int j=0;j<k && flag==0;j++)
            {
                if(k_cut[j][0]<=k_cut[j][1])
                {
                    if(k_cut[j][0]<p_cut[i] && k_cut[j][1]>=p_cut[i])
                    {
                        flag=1;
                    }
                }
                else
                {
                    if(k_cut[j][0]> k_cut[j][1])
                    {
                        if((k_cut[j][0]<p_cut[i] && p_cut[i]<=n) || ( p_cut[i]>=1 &&  p_cut[i]<=k_cut[j][1]))
                            flag=1;
                    }
                }
            }
        }
        if(flag==0)
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
