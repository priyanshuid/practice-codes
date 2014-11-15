/**
Finding nth root of a real number using newton raphson method.
we assume that f(x)= x^n-k
f'(x) = n*x^(n-1).
We assume an intial value taken from the user and improvise the
value of the root.

x(n+1) = x(n) - f(x)/f'(x).

we stop when the value of |x(n+1)-x(n)| is less than epsilon choosen by user.
**/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;
double diff(double a, double b){
    return (a>b)?(a-b):(b-a);
}
//f(x, n) -> raise x to n
double find_pow(double x, int n){

    if(n==0)    return 1;

    if(n==1)    return x;

    if(n%2==0)
        return find_pow(x, n/2)*find_pow(x, n/2);

    else    return find_pow(x, n/2)*find_pow(x, n/2)*x;
}
// f(x) taken in the question
double function( double x, int n,double val){
    return find_pow(x, n) - val;
}
//f'(x) taken in the question
double function_derivative(double x, int n, double val){

    if(n==1)
        return 1;
    return n*find_pow(x, n-1);
}
//driving function
double find_root(double val, int n, double error){
    double previous_root=2.0;
    double root=previous_root - function(previous_root, n, val)/function_derivative(previous_root, n, val);
    while(diff(root, previous_root) >= error){
        previous_root= root;
        root= previous_root - function(previous_root, n, val)/function_derivative(previous_root, n, val);
    }
    return root;
}
// test function
int main()
{
    float val;
    int n;
    int decimal_value;   //correct to these many decimal places
    cin>>val>>n>>decimal_value;
    double error=1;
    for(int i=0;i< decimal_value;i++){
        error/= 10;
    }
    cout<<find_root(val, n, error)<<endl;
    return 0;
}
