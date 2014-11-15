#include <iostream>
using namespace std;
int main()
{
int x=5;
x= x-++x-1;
cout<<x<<endl;
x=5;
x-=x++;
cout<<x<<endl;
x=5;
x=x+1- --x;
cout<<x<<endl;
x=5;
x=x-1- --x;
cout<<x<<endl;
return 0;
}
