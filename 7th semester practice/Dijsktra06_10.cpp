#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 100000000
using namespace std;
int dist[100000];
int seen[100000];
int parent[100000];
struct compare{
    bool operator() (pair<int, int> p1, pair<int, int> p2){
        return p1.second>p2.second;
    }
};
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector <pair <int, int> > graph[n];
    priority_queue <pair<int, int> , vector <pair<int, int> >, compare> Q;
    for(int i=0;i<n;i++){
        dist[i]= INF;
        parent[i]=-1;
        seen[i]=0;
    }
    int s, t;
    cin>>s>>t;
    dist[s]=0;
    parent[s]=0;
    Q.push(pair<int, int> (s, 0));
    while(!Q.empty()){
        pair <int, int> top= Q.top();
        int u=top.first;
        if(seen[u]!=1){
            for(int j=0;j<graph[u].size();j++){
                pair <int, int> n2 = graph[u][j];
                int v=n2.first;
                int w=n2.second;
                if(!seen[v] && dist[v]> dist[u]+ w){
                    dist[v]= dist[u]+w;
                    Q.push(pair<int, int> (v, dist[v]));
                }
            }
        }
        Q.pop();
        seen[u]=1;
    }
    return 0;
}
