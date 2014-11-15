#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1000000000
typedef struct node node;
using namespace std;
int pos[1000000];
int d[10000000];
int parent[10000000];
struct node
{
    int val;
    int key;
};
struct gnode
{
    int dest;
    int weight;
};
bool operator<(const node &n1,const node &n2)
{
    return n1.key<n2.key;
}
bool operator>(const node &n1, const node &n2)
{
    return n1.key > n2.key;
}
void min_heapify(node ar[], int i , int n)
{
    int l=2*i;
    int r=2*i+1;
    int smallest=i;
    if(l<n && ar[l]<ar[i])
        smallest=l;
    else if(r<n && ar[r]<ar[l])
        smallest=r;
    if(smallest!=i)
    {
        node temp=ar[i];
        ar[i]=ar[smallest];
        ar[smallest]=temp;

        int t=pos[ar[smallest].val];
        pos[ar[smallest].val]=pos[ar[i].val];
        pos[ar[i].val]=t;

        min_heapify(ar, smallest, n);
    }
}
node top(node ar[])
{
    return ar[0];
}
void delete_top(node ar[],int *siz)
{
    ar[0]=ar[*siz-1];
    pos[ar[0].val]=(*siz)-1;
    *siz=(*siz)-1;
    min_heapify(ar,0 ,*siz);
}
void build_heap(node ar[], int n, int *size)
{
    *size=n;
    for(int i=n/2;i>=0;i--)
        min_heapify(ar, i , n);
}
bool is_empty(node ar[],int n)
{
    if(n>0)
        return false;
    return true;
}
void decrease_key(node ar[], int i , int size, int value)
{
    if(i>0)
    {
        ar[i].key=value;
        int parent=i/2;
        if(ar[parent]>ar[i])
        {
            node temp=ar[i];
            ar[i]=ar[parent];
            ar[parent]=temp;
            int t=pos[ar[i].val];
            pos[ar[i].val]=pos[ar[parent].val];
            pos[ar[parent].val]=pos[ar[i].val];
            decrease_key(ar, i/2 , size, ar[i/2].key);
        }
    }
}
void Prim_MST(vector <gnode> graph[], int n, int init)
{
    for(int i=0;i<n;i++)
    {
        d[i]=INF;
        parent[i]=-1;
    }
    d[init]=0;
    node ar[n];
    for(int i=0;i<n;i++)
    {
        ar[i].val=i;
        ar[i].key =INF;
        pos[ar[i].val]=i;
    }
    int size_of_heap;
    build_heap(ar,n,&size_of_heap);
    while(is_empty(ar,size_of_heap))
    {
        node k=top(ar);
        delete_top(ar, &size_of_heap);
        vector <gnode> ::iterator p;
        for(p=graph[k.val].begin(); p!=graph[k.val].end();p++)
        {
            if(d[(*p).dest] > d[k.val] + (*p).weight)
            {
                d[(*p).dest]=d[k.val] + (*p).weight;
                int position=pos[(*p).dest];
                decrease_key(ar, position, size_of_heap , d[k.val] + (*p).weight);
                parent[(*p).dest]= k.val;
            }
        }
    }
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector <gnode> ar[n];
    for(int i=0;i<m;i++)
    {
        int a, b, weight;
        cin>>a>>b>>weight;
        gnode n1;
        n1.dest=b;
        n1.weight=weight;
        ar[a].push_back(n1);
    }
    Prim_MST(ar, n , 0);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(d[i]!=INF)
        sum+=d[i];
    }
    cout<<sum<<endl;
    return 0;
}
