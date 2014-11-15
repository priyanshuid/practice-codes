#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;
int reverse(int a){
    int rev=0;
    while(a != 0){
        int r= a%10;
        rev = rev*10 + r;
        a=a/10;
    }
    return rev;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        int rev_a = reverse(a), rev_b = reverse(b);
        cout << reverse(rev_a + rev_b)<<endl;
    }
    return 0;

}
