#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int main(){
    int n;
    int flag=0;
    while(flag == 0){

        cin>>n;

        if(n == 42){
                flag=1;
                cin>>n;
                break;
        }cout<<n<<endl;

    }
    return 0;
}
