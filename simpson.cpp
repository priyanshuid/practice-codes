#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<fstream>
using namespace std;
double func(float x)
{
    float k=1/(1+x);
    return k;
}
int main()
{ 
  fstream myfile;
  myfile.open("simpson.txt");
    float a=0,b=1,n=2;
    float h=(b-a)/(2*n);
    float sum;
    for(int i=0;i<=2*n;i++)
    {
        if(i==0)
        sum+=func(a);
        else if(i==2*n)
            sum+=func(b);
        else if(i%2!=0)
            sum+=4*(func(a+i*h));
        else if(i%2==0)
            sum+=2*(func(a+i*h));
    }
    float res=(h/3)*(sum);
   myfile<<res;
   myfile.close();
    return 0;
}
