#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#define INF 100000000
using namespace std;
struct node{
    int id;
    int weight;
};
//need to keep track of positions of the nodes in order to use it in decreaseKey method
// so we'll use a pos array to store the positions of the nodes in the array!!

int pos[10000];
void minHeapify(vector <node> minHeap, int i, int n);
void decreaseKey(vector <node> minHeap, int k, int x);
void buildHeap(vector <node> minHeap, int n);
void extractMin(vector <node> minHeap);

void minHeapify(vector <node> minHeap, int i, int n){
    int left = 2*i+1;
    int right = 2*i+2;

    int smallest=i;

    if(right<n){
        if(minHeap[left].weight < minHeap[right].weight)
            smallest=left;
        else smallest= right;
    }else if(left < n)
    {
        if(minHeap[left].weight < minHeap[i].weight)
            smallest=left;
    }else return;

    if(smallest != i){

        pos[minHeap[smallest].id]]=i;
        pos[minHeap[i].id]=smallest;
        node temp = minHeap[i];
        minHeap[i] = minHeap[smallest];
        minHeap[smallest] = temp;

        minHeapify(minHeap, smallest, n);
    }
    return;
}

void buildHeap(vector <node> minHeap, int n){
    for(int i=n/2; i>=0; i--){
        minHeapify(minHeap, i , n);
    }
}

void deacreaseKey(vector <node> minHeap, int k,  int x, int n){

    int ps = pos[k];
    minHeap[ps].wight = x;

    while(i>=0 && minHeap[ps].weight < minHeap[(int)(ps-1)/2].weight){
        pos[minHeap[ps].id]= (int)(ps-1)/2;
        pos[minHeap[(int)(ps-1)/2].id] = ps;
        node temp= minHeap[ps];
        minHeap[ps]= minHeap[(int)(ps-1)/2];
        minHeap[(int)(ps-1)/2] =temp;
    }
}

node extractMin(vector <node> minHeap, int &n){
    node value=  minHeap[0];

    pos[minHeap[0].id] = n-1;
    pos[minHeap[n-1].id]= 0;
    node temp = minHeap[n-1];
    minHeap[n-1] = minHeap[0];
    minHeap[0] = temp;
    minHeapify(minHeap, 0, n-1);
    *n= (*n)-1;
    return value;
}

void dijsktra(vector <graph> graph[], int start, int n, vector <int> minHeap){
    int heapSize= n;
    while(heapSize != 0){
        node min = extractMin(minHeap, heapSize);
        for(int i=0;i< graph[min.id].size();i++){
            if(minHeap[graph[min.id][i]] > )
        }

    }

}
int main(){
    int n, m;
    cin>>n>>m;
    vector <node> graph[n];
    vector <node> minHeap;
    for(int i=0;i<m;i++){
         int a,b;
         cin>>a>>b;
         int weight;
         cin>>weight;
         node temp;
         temp.id=b;
         temp.weight= weight;
         graph[a].push_back(temp);
    }
    int start;
    cin>>start;
    for(int i=0;i<n;i++){
        temp.weight= INF;
        node temp;
        temp.id = i;
        if(i== start){
            temp.wight = 0;
        }
        minHeap.push_back(temp);
        pos[i]=i;
    }
    return 0;
}
