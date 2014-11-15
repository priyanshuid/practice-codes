#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <stack>
#include <memory.h>
using namespace std;
int t_stamp; // global time stamp//
char color[10000];
int discover[10000];
int finish[10000];
class node
{
    public:
        int f_time;
        int value;
};
node *make_node(int val, int finish_time)
{
    node *n=new node();
    n->value=val;
    n->f_time=finish_time;
    return n;
}
bool operator<(const node &a, const node &b)
{
    return a.f_time<b.f_time;
}
void dfs(int n, vector <int> graph[]);
void DFS_MAIN(vector <int> graph[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(color[i]=='W')
            dfs(i, graph);
    }
}
void DFS_transpose(vector <int> transpose_graph[], vector <node*> finish_sorted)
{
    vector <node*>::iterator p;
    int count=0;
    for(p=finish_sorted.begin();p!=finish_sorted.end();p++)
    {
        cout<<"Component"<<++count<<":";
        if(color[(*p)->value]=='W')
            dfs((*p)->value, transpose_graph);
            cout<<endl;
    }
}
void dfs(int n, vector <int> graph[])
{
    cout<<n<<" ";
    color[n]='G';
    discover[n]=t_stamp;
    t_stamp++;
    vector <int>::iterator p;
    for(p=graph[n].begin();p!=graph[n].end();p++)
    {
        if(color[*p]=='W')
            dfs(*p,graph);
    }
    finish[n]=t_stamp;
    color[n]='B';
}
int main()
{
    int m,n;
    memset(discover, 0 , sizeof(discover));
    memset(finish, 0 , sizeof(finish));
    for(int i=0;i<10000; i++)
        color[i]='W';
    cin>>n>>m;
    vector <int> graph[n];
    vector <int> transpose_graph[n];
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        transpose_graph[b].push_back(a);
    }
    DFS_MAIN(graph,n);
    for(int i=0;i<10000; i++)
        color[i]='W';
    vector <node*> finish_sorted;
    for(int i=0;i<n;i++)
    {
        node *n1=new node();
        n1->value=i;
        n1->f_time=finish[i];
        finish_sorted.push_back(n1);

    }
    vector <node*> ::iterator beg=finish_sorted.begin();
    vector <node*> ::iterator en=finish_sorted.end();
    sort(beg, en);
    DFS_transpose(transpose_graph, finish_sorted);
    return 0;
}
