#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int main(){
    long long a,b,c;
    cin>>a>>b>>c;
    while(!(a==b && b==c && c==0)){
        if(b-a == c-b)  cout<<"AP "<<c+(c-b)<<endl;
        else if((int)(b/a) == (int)(c/b)) cout<<"GP "<<c*(c/b)<<endl;
        cin>>a>>b>>c;
    }
    return 0;
}
