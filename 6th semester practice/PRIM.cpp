#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#include <list>
#include <stack>
#include <math.h>
#include <memory.h>
#define INF 1000000000
using namespace std;
typedef struct hnode hnode;
typedef struct gnode gnode;
int pos[10000000];
int d[10000000];
int parent[10000000];
struct hnode
{
    int val;
    int key;
};
struct gnode
{
    int v;
    int weight;
};
bool operator<(const hnode &h1, const hnode &h2)
{
    return h1.key<h2.key;
}
bool operator>(const hnode &h1, const hnode &h2)
{
     return h1.key>h2.key;
}
void swap(hnode *h1,hnode *h2)
{
    hnode temp=*h1;
    *h1=*h2;
    *h2= *h1;
}
void heapify(hnode heap[], int size , int i)
{
    int l=2*i+1;
    int r=2*i+2;
    int smallest=i;
    if(l<size && heap[i] > heap[l])
        smallest=l;
    if(r<size && heap[l] > heap[r])
        smallest=r;
    if(smallest!=i)
    {
        int t=pos[heap[i].val];
        pos[heap[i].val]=pos[heap[smallest].val];
        pos[heap[smallest].val]=t;

        swap(&heap[i],&heap[smallest]);

        heapify(heap, size, smallest);
    }
}
void build_heap(hnode heap[], int n, int *size)
{
    *size = n;
    for(int i=n/2;i>=0;i--)
        heapify(heap,n,i);
}
void pop(hnode heap[], int *size)
{
    heap[0]=heap[*size-1];
    pos[heap[*size-1].val]=0;
    (*size)=(*size)-1;
    heapify(heap, *size , 0);
}
void decrease_key(hnode heap[], int i,int value)
{
    heap[i].key=value;
    if(i>0)
    {
        int parent=(i-1)/2;
        if(heap[i] < heap[parent])
        {
            int t=pos[heap[i].val];
            pos[heap[i].val]=pos[heap[parent].val];
            pos[heap[parent].val]=t;

            swap(&heap[i],&heap[parent]);

            decrease_key(heap, parent,value);
        }
    }
    else return;
}
hnode top(hnode heap[])
{
    return heap[0];
}
bool is_empty(hnode heap[], int size)
{
    return (size==0);
}
bool isInsideHeap(int size , int v)
{
    if(pos[v]>=0 && pos[v]<size)
        return true;
    return false;
}
void prim_MST(vector<gnode> graph[], int n, int init)
{
    hnode heap[n];
    for(int i=0;i<n;i++)
    {
        d[i]=INF;
        parent[i]=-1;
        heap[i].val=i;
        heap[i].key=INF;
    }
    heap[init].key=0;
    d[init]=0;
    int Size=0;
    build_heap(heap,n,&Size);
    while(!is_empty(heap,Size))
    {
        hnode t=top(heap);
        pop(heap,&Size);
        //cout<<t.val<<endl;
        vector <gnode>::iterator p;
        for(p=graph[t.val].begin() ; p!= graph[t.val].end(); p++)
        {
            cout<<d[t.val] << " "<< (*p).weight<<endl;
            if(isInsideHeap(Size,pos[(*p).v]) && d[(*p).v] > d[t.val] + (*p).weight)
            {
                d[(*p).v]= d[t.val] + (*p).weight;
                cout<<d[t.val] + (*p).weight<<endl;
                parent[(*p).v]=t.val;
                decrease_key(heap,pos[(*p).v],d[(*p).v]);
            }
        }
    }
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector <gnode> graph[n];
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        gnode n;
        n.v=b;
        n.weight=w;
        graph[a].push_back(n);
    }
    int sum=0;
    prim_MST(graph, n , 0);
    for(int i=0;i<n;i++)
    {
        if(d[i]!=INF)
            sum+=d[i];
    }
    cout<<sum<<endl;
    return 0;
}
