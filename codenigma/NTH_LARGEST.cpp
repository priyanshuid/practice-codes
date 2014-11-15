#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <fstream>
using namespace std;
struct point
{
    int val;
    int freq;
};
bool operator<(const point &p1, const point &p2)
{
    if(p1.freq> p2.freq)
        return true;
    else if(p1.freq== p2.freq)
        return p1.val<p2.val;
    else return false;
}
int main()
{
    int m,n,k,a;
    ifstream in("nlarge_input.txt");
    in>>m>>n>>k;
    point p[k+1];
    memset(p , 0, sizeof(p));
    for(int i=0;i<m;i++)
    {
        in>>a;
        p[a].freq++;
        p[a].val=a;
    }
    sort(p,p+k+1);
    int count=1;
    int flag=0;
    int i;
  //  for(int i=0;i<=k;i++)
       // cout<<p[i].val<<" "<<p[i].freq<<endl;
    if(n==1)
        cout<<p[0].val<<endl;

    else
    {
        for(i=1;i<=k;i++)
        {
            if(p[i].freq < p[i-1].freq)
                count++;
            if(count==n)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            cout<<p[i].val<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}
