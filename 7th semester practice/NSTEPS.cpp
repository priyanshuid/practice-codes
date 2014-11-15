#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x, y;
        cin>>x>>y;

        if(y == x || y == x-2)
        {
                if(x%2 ==0) cout<<x+y<<endl;
                else cout<< x+y-1<<endl;

        }else cout<<"No Number"<<endl;
    }
    return 0;
}
