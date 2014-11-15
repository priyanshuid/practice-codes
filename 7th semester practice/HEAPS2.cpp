/**
Heaps are dynamic data structures, which are very fast for extraction of maximum/minimum elements or infact
insertion of new elements into it.
Heaps are useful in implementation of priority queues.
Operations supported-
1: Extract Max/Min - Constast time.
2: Insert an element - Order (log n)
3: Decrease Key of a perticular node - Order (log n).
Working principle - We either percolate up or percolate down the effect, starting from an index.
Maintaing invariant at any instant after the heap is built
**/
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stack>
#include <vector>
#include <stdio.h>
using namespace std;
//Minheapify assumes that the whole array ar is min Heapified, already, except the current
// index to be minHeapified, i.e. , 'i'.
//Minheapify restores the invariant property of the heap.
void minHeapify(int *ar, int i, int n){
    //left child
    int l = 2*i+1;
    //right child
    int r = 2*i+2;
    int minimum = i;
    //we choose the minimum of the three elements
    // if the minimum is not the ith index element, we swap it with the minimum, and call the
    // minHeapify on that index with minimum value
    if(r < n){
    //case where both left and right child are present.
        if(ar[l]< ar[i] && ar[l]< ar[r])    minimum = l;
        else if(ar[r] < ar[i] && ar[r]< ar[l]) minimum = r;
    }else{
        if(l< n)    if(ar[l] < ar[i]) minimum = l;
        else return;
    }
    if(minimum != i){
        int temp=ar[i];
        ar[i]=ar[minimum];
        ar[minimum]= temp;
        //note the recursive call here on the minimumindex
        minHeapify(ar, minimum, n);
    }
}
// this function deletes the root element and returns it, that at any time, contains the minimum element
int extractMin(int *heap, int i, int &n){
    //case where the heap is empty
    if(n==0)    return -1;
    else {
        int val= heap[0];
        heap[0]=heap[n-1];
        n=n-1;
        //heapify after the deletion
        minHeapify(heap, 0, n);
        return val;
    }
}
//this function, against the extractMin, just gives the minimum value, without deleting it.
int giveMin(int *heap, int n){
    if(n==0)    return -1;
    else return heap[0];
}
//build a heap out of the array
void buildHeap(int *heap, int n){
    // we only need to heapify the indexes from n/2 to 0 because
    // higher indexed nodes represent heap of size of themselves.
    for(int i=n/2;i>=0;i--){
        minHeapify(heap, i, n);
    }
}
// decrease the value of the key, such that we know the index of the key.
void decreaseKey(int *heap, int i, int k, int n){
    heap[i] = heap[i]-k;
    if(i!=0){
        minHeapify(heap, i/2, n);
    }
}
//test run
int main(){
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)    cin>>ar[i];
    buildHeap(ar, n);
    int ans= giveMin(ar, n);
    if(ans!=-1) cout<<ans<<endl;
    for(int i=0;i<n;i++) cout<<ar[i]<<" ";
    decreaseKey(ar, 3, 2, n);
    cout<<endl;
    for(int i=0;i<n;i++) cout<<ar[i]<<" ";
    int ans2=giveMin(ar, n);
    cout<<endl;
    cout<<ans2<<endl;
    return 0;
}
