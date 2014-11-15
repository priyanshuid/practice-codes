#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <queue>
#define INF 10000000
typedef struct node node
using namespace std;
int weigh[1000][1000];
int d[1000];
struct node
{
    int u;
    int weight;
};
bool operator<(const edge &e1, const edge &e2)
{
    return e1.weight<e2.weight;
}
int main()
{
    int n,m;
    cin>>n>>m;
    priority_queue <node> Q;
    for(int i=0;i<m;i++)
    {
        int u1,v1,w1;
        cin>>u1>>v1>>w1;
        weigh[u1][v1]=w1;
        weigh[v1][u1]=w1;
        d[u1]=
    }

    return 0;
}
