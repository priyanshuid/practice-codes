/**
Dijkstra's algorithm is used to find minimum distance from a node ('S') to every other node
in the graph.
We have used a pre-defined priority queue for the algorithm.
Graph is represented as an adjacency list.
**/
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <queue>
#include <priority_queue>
#include <stack>
#define pii pair<int, int>
#define INF 10000000000
//compare function for the priority queue
// we denote every node that has to be stored in priority queue as a pair of the node id and
// the current minimised distace
struct compare{
    bool operator() (const pii &a, const pii &b){
        return a.second<b.second;
    }
}
bool seen[100000];
int dist[100000];
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    vector<pii> graph[n];
    //directed graph creation
    for(int i=0;i<m;i++){
        int a, b, w;// edge(a -> b) with weight= w
        cin>>a>>b>>w;
        graph[a].push_back(pii(b, w));
    }
    //priority queue to perform dijkstra's algorithm.
    priority_queue <pii, compare()> Queue;
    int start;
    cin>>start;
    // we set the distace of the start node as 0 and other node as INF
    for(int i=0;i<n;i++){
        if(i==start){
            dist[i]=0;
            continue;
        }
        dist[i]=INF;
        seen[i]=0;
    }
    Q.push_back(pii(start, 0));
    while(!Q.empty()){
        pii node = Q.front();
        if(seen[node.first]==1){
            continue;
        }
        for(int j=0;j != graph[node.first].size(); j++){
            //temp node to keep the current node being checked.
            pii node temp= graph[node.first][j];
            int v= temp.first;  // node id
            int d= temp.second; //distance value
            if(!seen[v] && dist[v] > dist[node.first]+ d){
                dist[v]= dist[node.first] + d;
                Q.push_back(pii(v, dist[v]));
            }
        }
        seen[node.first]=1 ; // set the seen bit of this node to be 1 so as not to visit it again
    }
    return 0;
}
