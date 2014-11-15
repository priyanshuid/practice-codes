#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
typedef struct node node;
using namespace std;
struct node
{
    int v;
    int weight;
};
bool operator<(const node &n1,const node &n2)
{
    return n1.weight<n2.weight;
}
void min_heapify(node *heap[], int i, int n)
{
    int l=2*i;
    int r=2*i+1;
    int min_pos=i;
    if(l<=n && heap[l] < heap[i])
        min_pos=l;
    else if(r<=n && heap[r]< heap[l])
        min_pos=r;
    if(min_pos!=i)
    {
        node *temp=heap[i];
        heap[i]=heap[min_pos];
        heap[min_pos]=heap[i];
        min_heapify(heap, min_pos,n);
    }
    return;
}
void build_heap(node *heap[], int n)
{
    int size_heap=n;
    for(int i=n/2;i>=1;i--)
        min_heapify(heap, i , n);
}
node *extract_min(node *heap[],int n)
{
    if(n>=1)
        return heap[1];
    else return NULL;
}
void pop_top(node *heap[], int &n)
{
    if(n>=1)
    {
        heap[1]=heap[n];
        n=n-1;
        min_heapify(heap, 1, n);
    }
}
int main()
{
    int n;
    cin>>n;
    node *heap[n+1];
    for(int i=1;i<=n;i++)
    {
        heap[i] =new node();
        cin>>heap[i]->v>>heap[i]->weight;
    }
    build_heap(heap,n);
    node *tt=extract_min(heap,n);
    cout<<tt->v<< tt->weight <<endl;
    pop_top(heap, n);
    node *tt1=extract_min(heap,n);
    cout<<tt1->v<< tt1->weight <<endl;
    return 0;
}
