#include <iostream>
#include <math.h>
#include <memory>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
int indx[20005];
int segTree[49999];
int ar[20005];
void update(int *segTree, int updateIndex, int st, int en, int index){
    if(st> en || updateIndex < st || updateIndex > en)    return;
    if(st== en) {
            segTree[index]--;
            return;
    }
    else{
        segTree[index] = segTree[index] -1;
        int mid= st+ (en-st)/2;
        update(segTree, updateIndex, st, mid, 2*index);
        update(segTree, updateIndex, mid+1, en, 2*index+1);
    }
}
int query(int *segTree, int l , int r, int st, int en, int index){
    if(en < l || r < st || en < st) return 0;
    if(l<=st &&  r>= en)    return segTree[index];
    else {
            int mid= st+ (en-st)/2;
            return query(segTree, l, r, st, mid, 2*index)+query(segTree, l, r, mid+1, en, 2*index+1);
    }
}
int construct(int *segTree, int *ar, int st, int en, int index){
    if(st>en) return 0;
    if(st == en) {
        segTree[index] = ar[st];
        return segTree[index];
    }
    else {
        int mid= st+ (en-st)/2;
        segTree[index] = construct(segTree, ar, st, mid, 2*index)+construct(segTree, ar, mid+1, en, 2*index+1);
        return segTree[index];
    }
}
int main(){
    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            ar[i]=1;
        }
        memset(indx, 0, sizeof(indx));
        int val=construct(segTree, ar, 1, n, 1);
      //  cout<<query(segTree, 1, 3, 1, n, 1)<<endl;
        int ind=0;
        for(int j=1;j<=n;j++){
            int jump= j+1;
            while(jump !=0){
           //     cout<<jump<<endl;
                if(ind + jump > n){
                    jump -= query(segTree, ind+1, n, 1, n, 1);
                    ind=0;
                }else {
                    int temp= jump;
                    jump -=query(segTree, ind+1, ind+jump, 1, n, 1);
                    ind= temp+ind;
                }
            }
         //   cout<<ind<<endl;
            indx[ind]=j;
            update(segTree, ind, 1, n, 1);
        }
        for(int i=1;i<=n;i++)   cout<<indx[i]<<" ";
        cout<<endl;
       // cout<<"A"<<endl;
    }
    return 0;
}
