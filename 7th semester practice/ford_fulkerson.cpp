#include <iostream>
#include <math.h>
#include <stdio.h>
#include <queue>
#include <memory.h>
#include <vector>
#define INF 10000000
using namespace std;
int capacity[1000][1000];
int parent[1000];
int visited[1000];
int bfs(vector <int> graph[], int n, int source, int sink){
    queue <int> Queue;
    Queue.push(source);
    visited[source]=1;
    int flag=0;
    int v;
    while(!Queue.empty() && flag==0){

        int u= Queue.front();
        Queue.pop();
        for(int i=0;i !=graph[u].size(); i++){
            v= graph[u][i];
            if(!visited[v] && capacity[u][v] >0){
                parent[v]=u;
                visited[v]=1;
                Queue.push(v);
                if(v == sink)
                {
                    flag=1;
                    break;
                }
            }
        }
    }
    int path_cap=INF;
    while(parent[sink] != -1){
        int u=parent[sink];
        path_cap = min(path_cap, capacity[u][sink]);
        sink= parent[sink];
    }
    while(parent[sink] != -1){
        int u=parent[sink];
        capacity[u][sink] -= path_cap;
        capacity[sink][u] += path_cap;
        sink= parent[sink];
    }
    if(path_cap != INF)
        return path_cap;
    else return 0;
}
int ford_fulkerson(vector <int> graph[], int n, int source , int sink){
    int total_path_cap =0;
    while(true){
        int path_cap= bfs(graph, n, source, sink);
        cout<<"A"<<endl;
        if(path_cap==0)
            break;
        else total_path_cap +=path_cap;
        memset(visited, 0 , sizeof(visited));
        for(int i=0;i<n;i++)    parent[i]=-1;
    }
    return total_path_cap;
}

int main(){
        int n, m;
        cin>>n>>m;
        vector <int> graph[n];
        memset(capacity, 0, sizeof(capacity));
        for(int i=0;i<m;i++){
            int a, b, w;
            cin>>a>>b>>w;
            graph[a].push_back(b);
            capacity[a][b]=w;
        }
        for(int i=0;i<n;i++){
            parent[i]=-1;
            visited[i]=0;
        }
        int source, sink;
        cin>>source>>sink;

        int val= ford_fulkerson(graph, n, source, sink);
        cout<<val<<endl;
        return 0;
}
