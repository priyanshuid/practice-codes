// Kruskal's algo
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int parent[10000];
bool compare(const pair<int, pair <int, int> > &p1,const pair<int, pair<int, int> > &p2){
    return p1.second.second < p2.second.second;
}
int findParent(int x){
    if(x!=parent[x]){
        parent[x]=x;
        findParent(parent[x]);
    }
    return x;
}
int main(){
    vector <pair <int, pair<int, int> > > graph, mst;
    int n,m;
    cin>>n>>m;
    for(int j=0;j<m;j++){
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        graph.push_back(pair<int, pair<int, int> >(a, pair <int, int> (b, w)));
    }
    sort(graph.begin(), graph.end(), compare);
    for(int i=0;i<n;i++)    parent[i]=i;
    int totalLength=0;
    for(int i=0;i<n-1;i++){
        pair <int, pair<int , int > > edge= graph[i];
        int u= edge.first;
        int v= edge.second.first;
        int w= edge.second.second;

        if(findParent(u) != findParent(v)){
            mst.push_back(edge);
            parent[u]= parent[v];
            totalLength+=w;
        }
    }
    cout<<"Total Length:" <<totalLength<<endl;
    return 0;
}
