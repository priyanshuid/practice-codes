#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
    long long int a;
    scanf("%lld", &a);
    long long k= a% (long long int)6;
    if(k==0ll || k==1ll || k==3ll)
        cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}
