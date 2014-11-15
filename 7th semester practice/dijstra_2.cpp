#include <iostream>
#include <math.h>
#include <stdio.h>
#include <cstdio>
#include <queue>
using namespace std;
#include <stack>
#define pii pair<int, int>
#define INF 100000000
struct compare{
    bool operator() (const pii &a, const pii &b){
        return a.second<b.second;
    }
};
bool seen[100000];
int dist[100000];

int main(){
    int n, m;
    cin>>n>>m;
    vector<pii> graph[n];
    for(int i=0;i<m;i++){
        int a, b, w;
        cin>>a>>b>>w;
        graph[a].push_back(pii(b, w));
    }

    priority_queue <pii, vector <pii>,compare> Q;
    int start;
    cin>>start;
    for(int i=0;i<n;i++){
        if(i==start){
            dist[i]=0;
            continue;
        }
        dist[i]=INF;
        seen[i]=0;
    }
    Q.push(pii(start, 0));
    while(!Q.empty()){

        pii node = Q.top();
        if(seen[node.first]==1){
            continue;
        }
        for(int j=0;j != graph[node.first].size(); j++){

            pii node= graph[node.first][j];
            int v= node.first;
            int d= node.second;
            if(!seen[v] && dist[v] > dist[node.first]+ d){
                dist[v]= dist[node.first] + d;
                Q.push(pii(v, dist[v]));
            }
        }
        seen[node.first]=1 ;
    }
    return 0;
}
