#include <bits/stdc++.h>
using namespace std;
int findParent(int x,int parent[]){
    if(parent[x]!=x){
        parent[x]=findParent(parent[x], parent);
    }
    return parent[x];
}
int main(){
    int n,m;
    cin>>n>>m;
    vector <pair <int, int> > graph;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph.push_back(pair<int, int>(a,b));
    }
    int parent[n+5];
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    int flag=0;
    for(int i=0;i<m;i++){
        int u=graph[i].first;
        int v=graph[i].second;
        int pu= findParent(u, parent);
        int pv= findParent(v, parent);
        if(pu!=pv){
            parent[pu]=parent[pv];
        }else{
            flag=1;
            break;
        }
    }
    if(flag==1){
        cout<<"NO"<<endl;
    }else cout<<"YES"<<endl;
}
