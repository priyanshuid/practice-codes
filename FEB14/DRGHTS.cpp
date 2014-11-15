#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <memory.h>
using namespace std;
int open_window[50005];
int visited[50005];
int status[50005];
void dfs(vector <int>graph[],int i,long long *count)
{
    visited[i]=1;
    if(open_window[i])
    {
        (*count)=(*count)+1;
    }
    for(int j=0;j<graph[i].size();j++)
    {
        if(!visited[graph[i][j]])
            dfs(graph,graph[i][j],count);
    }
}
int dfs2(vector <int>graph[],int i)
{
    int sta[50005];
    int top=-1;
    sta[++top]=i;
    int cc=0;
    visited[i]=1;
    //int status=1;
    int flag=1;
    int index_to_resume;
    int pre_status;
    while(top!=-1)
    {
        int h=sta[top];
        int count=0;
        for(int j=0;j<graph[h].size();j++)
        {
            if(!visited[graph[h][j]])
            {
                sta[++top]=graph[h][j];
                visited[graph[h][j]]=1;
                count++;
                flag=1;
            }

        }
        if(count==0)
        {
            if(flag==1)
            {
                status[sta[top]]=open_window[sta[top]];
                if(status[sta[top]]==1 || index_to_resume==top)
                {    cc++;
                     pre_status=1;
                     }
                else pre_status=0;
            }
            if(flag==0)
            {
                if(pre_status==1)
                {
                    cc++;
                    status[sta[top]]=1;
                }
                if(open_window[sta[top]])
                {
                    cc++;
                    pre_status=1;
                    status[sta[top]]=1;
                }
            }
            top--;
            if(pre_status==1)
                index_to_resume=top;
            flag=0;

        }
    }
    return cc;
}
int dfs3(vector <int> graph[],int i,int *count,int *c_nodes)
{
    visited[i]=1;
    int ret_v=0;
    int ff=0;
    if(open_window[i]==1)
    {
        status[i]=0;
        (*c_nodes)++;
    }
    for(int j=0;j<graph[i].size();j++)
    {
        if(visited[graph[i][j]]==0)
            ff+=dfs3(graph,graph[i][j],count,c_nodes);
    }
    if(open_window[i]==1 || ff!=0)
        {
            (*count)++;
            ret_v=1;
            }
    return ret_v;
}
int main()
{
    memset(visited, 0 , sizeof(visited));
    memset(open_window, 0 , sizeof(open_window));
    memset(status,0,sizeof(status));
    int n,m;
    scanf("%d%d",&n,&m);
    vector <int> graph[n+1];
    for(int i=0;i<n;i++)
       { cin>>open_window[i];
            status[i]=open_window[i];
            }
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    long long int count=0;
    for(int i=0;i<n;i++)
    {
        long long val=0;
        if(!visited[i])
         {   dfs(graph,i,&val);
             //cout<<val<<endl;
             if(val>=2)
             count+=val*(val-1)/2;
             }
    }
    int val1=0;
    memset(visited,0,sizeof(visited));
    for(int i=0;i<n;i++)
    {
        if(status[i]==0)
            continue;
        int t=0;
        int count2=0;
        dfs3(graph,i,&count2,&t);
       // cout<<t<<endl<<count2<<endl;
        if(t>=2)
        {
            val1+=count2;
        }
    }
    cout<<count<<" "<<val1<<endl;
    return 0;
}
