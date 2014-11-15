#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
typedef struct node node;
using namespace std;
struct node
{
    int val;
    int pos;
};
bool operator<(const node &n1, const node &n2)
{
    return n1.val>n2.val;
}
int main()
{
    int t;
    scanf("%d", &t);
    for(int t1=0;t1<t;t1++)
    {
        int n,k,s;
        scanf("%d %d %d", &n, &k, &s);
        int A_1[n+1];
        priority_queue<node>Q;
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &A_1[i]);
            node nd;
            nd.val=A_1[i];
            nd.pos=i;
            Q.push(nd);
        }
        while(!Q.empty())
        {
            node k=Q.top();
            cout<<k.pos<<" ";
            Q.pop();
        }
        cout<<endl;
    }
    return 0;
}
