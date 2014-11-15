#include <iostream>
#include <math.h>
#include <queue>
#include <stack>
#include <stdio.h>
#include <vector>
#include <memory.h>
#include <bitset>
using namespace std;
int level[10000];
int parent[10000];
char color[10000];
int DFS_Parent[10000];
int finish_time[10000];
int start_time[10000];

void BFS(vector <int> graph[], int n, int s){
    queue <int> frontier;
    queue <int> next;
    frontier.push(s);
    parent[s]=-1;
    level[s]=0;
    int lev = 1;
    while(!frontier.empty()){

        while(!frontier.empty()){
            int val= frontier.front();
            frontier.pop();
            for(int i=0;i!=graph[val].size();i++){
                if(level[i] == 0){
                    parent[graph[val][i]]=val;
                    next.push(graph[val][i]);
                    level[graph[val][i]]= lev;
                }
            }
        }
        while(!next.empty()){
            frontier.push(next.front());
            next.pop();
        }
        lev++;
    }
}
void DFS_Visit(vector <int> graph[], int i){
    time++;
    start_time[i]=time;
    color[i]='g';
    for(int j=0;j!= graph[i].size();j++){
        if(color[i]=='w'){
            parent[graph[i][j]]=i;
            DFS_Visit(graph, j);
        }
    }
    time++;
    finish_time[i]=time;
    color[i]='b';
    return;
}
void DFS(vector <int> graph[], int n){
    for(int i=0;i<n;i++){
        color[i]='w';
        DFS_Parent[i]=-1;
    }
    for(int i=0;i<n;i++){
        if(color[i]=='w'){
            DFS_Visit(graph, i);
        }
    }
    return;
}
int main(){
    int n,m;
    cin>>n>>m;
    memset(level, 0, sizeof(level));
    vector <int> graph[n];
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    int s;
    cin>>s;
    BFS(graph, n, s);
//    DFS(graph);
    return 0;
}
