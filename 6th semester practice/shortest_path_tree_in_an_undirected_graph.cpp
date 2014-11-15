#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#define INF 10000000
using namespace std;
void shortest_path(vector <int> ar[],int n,int st_node,int parent[])
{
    queue <int> Q;
    char status[n];
    int d[n];
    for(int i=0;i<n;i++)
    {
        parent[i]=-1;
        status[i]='U';
        d[i]=INF;
    }
    status[st_node]='C';
    d[st_node]='S';
    parent[st_node]=-1;
    Q.push(st_node);
    while(!Q.empty())
    {
        vector<int>::iterator p;
        for(p=ar[Q.front()].begin();p!=ar[Q.front()].end();p++)
        {
            if(status[*p]=='U')
            {
                Q.push(*p);
                parent[*p]=Q.front();
                d[*p]=d[Q.front()]+1;
                status[*p]='C';
            }
        }
        status[Q.front()]='V';
        Q.pop();
    }
}
int main()
{
    int n,q;
    cin>>n>>q;
    vector <int> my_graph[n+1];
    int parent[n+1];
    for(int i=0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        my_graph[a].push_back(b);
        my_graph[b].push_back(a);
    }
    int st_node;
    cout<<"Enter Starting Node:";
    cin>>st_node;
    shortest_path(my_graph,n+1,st_node,parent);
    bool flag=true;
    for(int i=1;i<=n;i++)
        if(i!=4)cout<<parent[i]<<endl;
return 0;
}
