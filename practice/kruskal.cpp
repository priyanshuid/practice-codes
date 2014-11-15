#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <memory.h>
#include <stack>
#include <math.h>
#include <algorithm>
using namespace std;
int parent[100000];
int rank[100000];
class edge
{
    public:
        int u,v;
        int weight;
        edge(int u1, int v1)
        {
            u=u1;
            v=v1;
            weight=0;
        }
};
edge *make_edge(int u, int v, int w)
{
    edge *edg=new edge(u, v);
    (*edg).weight=w;
    return edg;
}
bool operator<(const edge &a, const edge &b)
{
    return a.weight>b.weight;
}
void make_set(int a);
int find(int);
void link(int, int);
void make_set(int a)
{
    parent[a]=a;
    rank[a]=0;
}
void union_of(int a,int b)
{
    link(find(a),find(b));
}
int find(int a)
{
    if(parent[a]!=a)
        parent[a]=find(parent[a]);
    return parent[a];
}
void link(int a,int b)
{
    if(rank[a]==rank[b])
    {
        parent[a]=b;
        rank[b]++;
    }
    else
    {
        if(rank[a]>rank[b])
            parent[b]=parent[a];
        else   parent[a]=parent[b];
    }
}
int main()
{
    int n, m; //   n= no. of vertices and m=no. of edges
    cin>>n>>m;
    memset(rank, 0, sizeof(rank));
    memset(parent, 0 , sizeof(parent));
    priority_queue <edge> Q;
    for(int i=0;i<m;i++)
    {
        int a,b;
        int weight;
        scanf("%d %d %d",&a, &b, &weight);
//        ar[a].push_back(make_node(b,weight));
        edge *edg=new edge(a, b);
        (*edg).weight=weight;
        Q.push(*edg);
    }
    for(int i=0;i<n;i++)
        make_set(i);
    int count_edge=0;
    while(!Q.empty())
    {
        if(count_edge==n-1)
            break;
        edge edg=Q.top();
        if(find(edg.u) != find(edg.v))
        {
            union_of(edg.u,edg.v);
            cout<< edg.u<< "------>" << edg.v<<" ";
            count_edge++;
        }
        Q.pop();

    }
    if(Q.empty() && count_edge!=n-1)
        cout<< "Disconnected Graph and therefore Spanning Tree Not Possible";
    return 0;
}
