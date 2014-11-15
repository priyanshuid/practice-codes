#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;

void max_heapify(int *ar, int i, int heap_size){

    if(i>=heap_size-1)
        return;

    int l= 2*i+1;
    int r= 2*i+2;
    int max_of_three=i;

    if( l< heap_size && r< heap_size){
        if( ar[l]< ar[r])
            max_of_three= r;
        else max_of_three= l;
    }

    else if( l<heap_size && ar[i]< ar[l])
        max_of_three= l;


    if(max_of_three != i){

        int temp = ar[i];
        ar[i] = ar[ max_of_three];
        ar[max_of_three] = temp;
        max_heapify(ar, max_of_three, heap_size);
    }
    return;
}
void build_max_heap(int *ar, int heap_size){

    for(int i=heap_size/2; i>=0; i--)
        max_heapify(ar, i , heap_size);
    return;
}
void heap_sort(int *ar, int heap_size){

    if(heap_size == 0)
        return;
    build_max_heap(ar, heap_size);

    int temp= ar[0];
    ar[0]= ar[heap_size-1];
    ar[heap_size-1]=temp;

    heap_sort(ar, heap_size-1);
    return;
}
void increase_key(int *ar, int i , int k, int heap_size){

    if(i == 0)
        return;
    else {
        ar[i]= k;
        max_heapify(ar, i/2 , heap_size);
    }
    return;
}
void decrease_key(int *ar, int i, int k, int heap_size){

        ar[i]=k;
        max_heapify(ar, i, heap_size);
        return;
}
void change_key(int *ar, int i, int k, int heap_size){

    if(ar[i] > k)
        decrease_key(ar, i, k, heap_size);
    else if(ar[i] < k)
        increase_key(ar, i, k, heap_size);
    else return;
}
int main()
{
    int n;
    cin>>n;
    int *ar = new int [n];
    for(int i=0;i<n;i++){
        scanf("%d", &ar[i]);
    }
    heap_sort(ar, n);
}
