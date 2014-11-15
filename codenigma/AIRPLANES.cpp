#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <fstream>
typedef struct node node;
using namespace std;
int time1;
struct node
{
    int val;
    int f_time;
};
char color[100000];
int finish[100000];
int dis[100000];
bool operator<(const node &n1, const node &n2)
{
    return n1.f_time > n2.f_time;
}
void dfs_go(vector <int> graph[], int init);
void dfs(vector <int> graph[],int n)
{
    for(int i=1;i<=n;i++)
    {
        color[i]='w';
        finish[i]=0;
        dis[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        if(color[i]=='w')
                dfs_go(graph, i);
    }
}
int dfs_transpose(vector <int> graph[], node ar[],int n)
{
    for(int i=1;i<=n;i++)
    {
        color[i]='w';
        finish[i]=0;
        dis[i]=0;
    }
    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(color[ar[i].val]=='w')
         {       dfs_go(graph,ar[i].val);
            count++;
        }
    }
    return count;
}
void dfs_go(vector <int> graph[], int init)
{
    color[init]='g';
    dis[init]=++time1;
    for(int i=0;i<graph[init].size();i++)
    {
        if(color[graph[init][i]]=='w')
        {
            dfs_go(graph,graph[init][i]);
        }
    }
    color[init]='b';
    finish[init]=++time1;
}
int main()
{
    int n, m;
    ifstream in("airplane_input.txt");
    in>>n>>m;
    time1=0;
    vector <int>graph[n+1];
    vector <int>graph_transpose[n+1];
    for(int i=0;i<m;i++)
    {
        int a,b;
        in>>a>>b;
        graph[a].push_back(b);
        graph_transpose[b].push_back(a);
    }
    dfs(graph,n);
    node ar[n];
    for(int i=1;i<=n;i++)
    {
        ar[i].val=i;
        ar[i].f_time=finish[i];
    }
    sort(ar+1,ar+n+1);
    //for(int i=1;i<=n;i++)
     //   cout<<ar[i].val<<endl;
    int val=dfs_transpose(graph_transpose,ar,n);
    cout<<val<<endl;
    return 0;
}
