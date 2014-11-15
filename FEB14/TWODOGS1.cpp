#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>
#define MAX 1000005
using namespace std;
int hash[1000005];
bool view[1000005];
int main()
{
    int n,k;
    for(int i=0;i<1000005;i++)
        hash[i]=1000005;
    scanf("%d%d",&n,&k);
    vector<int> same;
    for(int i=1;i<=n;i++)
    {
        int k1;
        cin>>k1;
        if(k1==k/2 && k%k1==0)
            {
                if(i<n/2+1)
                    same.push_back(i);
                else same.push_back(n-i+1);
            }
        else if(i<n/2+1)
        {
            if(hash[k1]>i)
                hash[k1]=i;
        }
        else
        {
            if(hash[k1]>n-i+1)
                hash[k1]=n-i+1;
        }
    }
    memset(view,0,sizeof(view));
   // for(int i=1;i<5;i++)
     //   cout<<hash[i]<<" ";
       // cout<<endl;
    int g_min=MAX;
    int val;
    for(int i=1;i<1000005;i++)
    {
        if(hash[i]==MAX)
            continue;
        if(i<k && view[i]==0 && hash[k-i]!=MAX)
         {   val=hash[i]+hash[k-i];
         //    cout<<val<<endl;
            g_min=min(val,g_min);
            view[i]=1;
            view[k-i]=1;
        }
    }
    int v1=MAX;
    //for(int i=0;i<same.size();i++)
       // cout<<same[i]<<endl;

    //    cout<<same[same.size()-1]<<endl;
      //  cout<<same[same.size()-2]<<endl;

 //   cout<<same[0]<<" "<<same[1]<<endl;
   // cout<<same[0]<<" "<<same[same.back()]<<endl;
   // cout<<same[same.back()]<<same[same.back()-1]<<endl;
    if(same.size()>=2)
    {
        v1=same[0]+same[1];
        v1=min(v1,same[0]+same.back());
        v1=min(v1,same.back()+same[same.size()-2]);
    }
    //cout<<v1<<endl;
     g_min=min(g_min,v1);
     if(g_min==1000005)
     cout<<-1<<endl;
     else
    cout<<g_min<<endl;
    return 0;
}
