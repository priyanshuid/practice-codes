#include <math.h>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
bool isOnHorizontalLine(long x, long y){
    if(y%2!=0)  return false;

    if(y==0){
        if(x==0 || x==1) return true;
    }else if(y>0){
        if(x <= y-1 && x>= -y)  return true;
    }else{
        if(x <= y+1 && x>= -y)  return true;
    }
    return false;
}
bool isOnVerticalLine(long x, long y){
    if(x > 0 && x%2 == 0) return false;
    if(x < 0 && x%2 != 0) return false;
    if(x == 0) return false;

    if(x == 1){
        if(y==0 || y==1) return true;
    }else if(x > 1){
        if(y >= -x+1 && y<= x+1) return true;
    }else{
        if(y >= -x && y <= x) return true;
    }
    return false;
}
int main(){

    int t;
    scanf("%d",&t);
    for(int t1=0;t1<t;t1++){
        long x,y;
        scanf("%ld %ld",&x, &y);
        if(isOnHorizontalLine(x,y) || isOnVerticalLine(x,y)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
