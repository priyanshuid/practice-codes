#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
int k;
using namespace std;
int one_d_peak_find(int *ar, int l, int r){
    int mid= l+ (r-l)/2;
    while(l<=r){
        if(ar[mid-1]<= ar[mid] && ar[mid]>= ar[mid]+1)
            return mid;
        else if(ar[mid]>=ar[mid-1])
            l=mid+1;
        else r= mid-1;
        mid=l+ (r-l)/2;
    }
    return mid;
}
int maximum_in_column(int ar[][1000], int column, int n){
    int max_val=-1;
    int max_val_index=0;
    for(int i=0;i<n;i++){
        if(max_val<ar[i][column])
        {
            max_val=ar[i][column];
            max_val_index=i;
        }
    }
    return max_val_index;
}

void two_d_peak_find(int ar[][1000], int r, int c, int *x, int *y){
    int l_column=0, r_column=c-1;
    int mid_column= l_column + (r_column-l_column)/2;
    int max=0;
    while(l_column<=r_column){
        if(l_column==r_column){
            max= maximum_in_column(ar, l_column, r);
            *x = max;
            *y = l_column;
            return;
        }
        else{
            max=maximum_in_column(ar, mid_column, r);
            if(ar[max][mid_column-1] <= ar[max][mid_column] && ar[max][mid_column+1] >= ar[max][mid_column])
            {
                *x = max;
                *y = mid_column;
                return;
            }else if(ar[max][mid_column-1]<= ar[max][mid_column]){
                l_column= mid_column+1;
            }else r_column = mid_column-1;
            mid_column= l_column + (r_column-l_column)/2;
        }
    }
    *x=max;
    *y=mid_column;
    return;
}

int main(){
    int n;
    cin>>n;
    int *ar= new int[n];
    k=n;

    for(int i=0;i<n;i++)
        cin>>ar[i];

    int pos= one_d_peak_find(ar, 0, n-1);
    cout<<pos<<endl;

    int r, c;
    cin>>r, c;
    int ar1[r][1000];

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>ar1[i][j];
        }
    }
    int *x,*y;
    two_d_peak_find(ar1, r, c, x, y);
    return 0;
}
