#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <memory.h>
using namespace std;
unsigned long table[50000000];
unsigned long calculate(unsigned long n){
    	if(n<=6)
            return n;
        else
        {
            unsigned long n1=n/2;
            unsigned long n2=n/3;
            unsigned long n3=n/4;
            if(n>50000000-1)
                return max(n,max(n1,calculate(n1))+max(n2,calculate(n2))+max(n3,calculate(n3)));
            else
            {
                if(table[n1]==0)
                    table[n1]=max(n1,calculate(n1));
                if(table[n2]==0)
                    table[n2]=max(n2,calculate(n2));
                if(table[n3]==0)
                    table[n3]=max(n3,calculate(n3));
                return max(n,table[n1]+table[n2]+table[n3]);
            }
        }
}
int main(){

    long n;

    memset(table, 0, sizeof(table));
    	while(scanf("%lu",&n)!=EOF)
        {
            unsigned long sum=calculate(n);
            cout<<sum<<endl;
        }
    return 0;
}
