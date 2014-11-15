/**
Programs to implement different sorting algorithms
1: insertion sort O(n^2)
2: selection sort O(n^2)
3: bubble sort  O(n^2)
4: merge sort  O(nlogn)
5: quick sort  Theta(nlogn)
Choice of the sorting alogrithm
Conditions -
1: In case you have a small array of sub-constant size , we usually prefer insertion sort
2: In case we have an almost sorted array,insertion sort outperforms the quick sort
3: Quick Sort has a worst case running time of O(n^2) , in case we have a reversed sorted array
4: Generally, we use merge/quick sort, because of their good running time
**/
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;
void insert_sort(int *ar, int l, int r){

    int i=l+1;
    for(; i< r+1; i++){
        int j=i-1;
        //have a window of increasing size such that the window elements are sorted at any instance
        while(j>=0 && ar[j]>ar[i])
        {
            //swap
            int temp= ar[i];
            ar[i]=ar[j];
            ar[j]=temp;
            j--;
        }
    }
}
void selection_sort(int *ar, int l , int r){

    //sorting by selection of minimum number in the updated array of decreasing size
    for(int i=l; i<r+1; i++){
        //minimum number
        int min= ar[i];
        int min_indx=i;
        for(int j=i;j<r+1;j++){
            if(ar[j]<min){
                min=ar[j];
                min_indx=j;
            }
        }
        if(i!=min_indx) {
        int temp=ar[i];
        ar[i]=ar[min_indx];
        ar[min_indx]=temp;
        }
    }
}
void bubble_sort(int *ar, int l, int r){
    // number bubble up to its appropriate position and this is done n times to sort the array
    for(int i=l;i<r+1;i++){
        for(int j=i; j<r+1 ; j++){
            if(ar[j] >  ar[j+1]){
                int temp=ar[i];
                ar[i]=ar[j];
                ar[j]=temp;
            }
        }
    }
}
// merge function to merge two sorted list
// called by merge_sort function
void merge(int *ar, int l, int mid, int r){

    //two finger pointer method to merge two sorted list
    //temp arrays to store the lists to be sorted
    int *a =new int[mid-l+1];
    int *b =new int[r-mid+1];
    int k=0;
    //initialise the lists
    for(int i=l; i<mid; i++){
        a[k]=ar[i];
        b[k]=ar[i+mid];
    }
    int a_index=0;
    int b_index=0;
    int ar_index=l;
    //fillinf the final sorted array
    while( ar_index!=r ){
        if(a[a_index] < b[b_index]){
            ar[ar_index]=a[a_index];
            a_index++;
        }else{
            ar[ar_index]=b[b_index];
            b_index++;
        }
        ar_index++;
    }
}
//recursive definition to sort the array
void merge_sort(int *ar, int l , int r){
    //termination condition
    if(l>=r)
        return ;
    else
    {
        int mid= l+ (r-l)/2;
        //recursive call to sort the decreasing size lists
        merge_sort(ar, l , mid);
        merge_sort(ar, mid+1, r);
        //merging the sorted lists using merge function
        merge(ar, l, mid, r);
        return;
    }
}
//funtion to find pivot position used by quick sort
// linear time function
int find_pivot(int *ar, int l, int r){

    int j=l+1;
    int pivot=l;
    // loop invariant ensures that the elements before j are smaller than ar[j] and elements after ar[j] are greater than that
    for(int i=l+1; i<=r; i++){
        if(ar[i]> pivot){
            int temp= ar[i];
            ar[i]=ar[j];
            ar[j]=temp;
            j++;
        }
    }
    //update pivot to the current j position
    int temp=ar[pivot];
    ar[pivot]=ar[j];
    ar[j]=temp;

    return j;
}
void quick_sort(int *ar, int l, int r){
    //termination condition
    if(l>=r)
        return;
    //find pivot
    int pivot= find_pivot(ar, l, r);
    // split the array into two subbarrays so as to recursively sort them.
    // recursive call
    quick_sort(ar, l, pivot-1);
    quick_sort(ar, pivot+1, r);
    return;
}

int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    insert_sort(ar, 0, n-1);
    bubble_sort(ar, 0, n-1);
    selection_sort(ar, 0, n-1);
    merge_sort(ar, 0, n-1);
    quick_sort(ar, 0, n-1);

    return 0;
}
