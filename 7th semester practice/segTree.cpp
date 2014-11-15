/**
    Segment tree is a recursive data structure used to perform the following queries on an array -
    query( a, b) - return the sum of all elements from a to b, i.e. , ar[a]+ ar[a+1]+ar[a+2]... ar[b]
    update( a, val) - update the value of ar[a] to val
    We can do the query on an array simply by keeping the running sum, but if we have multiple updates on the array,
    we'll need to shift the thereafter elements and thus, will end up having a O(n*nq) [nq= number of queries] solution.
    Segment trees have following complexities for these operations-
    Update - O(nu*logn) [nu- number of updates]
    Query -  O(nq*logn) [nq- number of queries]
    Building (just once) - O(n)

    In the following index, the index - 'index' corresponds to the entry in the segtree.



            [][][][][][][][]          |                     [0]                             left partition shows the actual array
               /        \             |               _ _ /     \_ _ _ _                             corresponding to which the right picture
        [][][][]        [][][][]      |            [1]                   [2]                   shows the segTree index .In code we
        /      \        /      \      |           /   \                /     \                have taken one indexed arrays
      [][]     [][]   [][]     [][]   |       [3]       [4]         [5]      [6]
      /  \     /  \   /  \     /  \   |       /  \      /  \        / \      /  \
     []  []   []  [] []  []   []  []  |    [7]    [8]  [9] [10]  [11] [12] [13] [14]
**/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
// function to update the tree according to the update performed at a perticular index of the
// array.
void update(int segTree[], int update_index, int value, int st, int en, int index){
    // index to be updated out of the range of update
    if(update_index < st || update_index > en)  return;
    //return criterion in case of bound termination
    if(en < st) return;
    else{
            // updation percolates down, i.e. , we update the root first,
            // then the subroot which contains the to-be-updated index and so on
            // going down.
            segTree[index] += value;
            int mid = st+ (en-st)/2;
            //recursively update the left and right subtree
            update(segTree, update_index, value, st, mid, 2*index+1); //left
            update(segTree, update_index, value, mid+1, en, 2*index+2); //right
    }
}
// function to perform the queries on a range (l, r) to sum up the
// values between the two indices.
int query(int segTree[], int l, int r, int st, int en, int index){
    //out of bound index simply return 0
    if(en< st || st > r || en < l) return 0;
    //if the indexes to be queried are contained in the current st and en, return the segtree
    // value corresponding to this subarray.
    else if( l <= st && r >= en)    return segTree[index];
    else {

       //else recurse.
        int mid = st+ (en -st)/2;
        return query(segTree, l, r, st, mid, 2*index+1)+query(segTree, l, r, mid+1, en, 2*index+2);
    }
}
//construction of the tree
int construct_tree(int segTree[], int ar[], int st, int en , int index){
    //return 0 in case starting index is greater than the end index
    if(st > en) return 0;
    else if( st == en) {
       //trivial insertion subtree size =1
        segTree[index] = ar[st];
        return segTree[index];
    }else {
        //recursive construction , we first construct the left subtree and the right subtree, and return the
        //value corresponding to these subtree.
        int mid= st+ (en-st)/2;
        segTree[index] = construct_tree( segTree, ar, st, mid, 2*index+1)+construct_tree(segTree, ar, mid+1, en, 2*index+2);
        return segTree[index];
    }
}
//test run
int main(){

    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)    cin>>ar[i];
    int segTree[2*n];
    int value= construct_tree(segTree, ar, 0, n-1, 0);
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(a==1){
            update(segTree, b-1, c, 0, n-1, 0);
        }else cout<<query(segTree, b-1, c-1, 0, n-1, 0)<<endl;
    }
    return 0;
}
