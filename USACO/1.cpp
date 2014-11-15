/*
ID: priyanshuid
PROG: test
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int main(){
    int a,b;
    ifstream in("test.in");
    ofstream out("test.out");
    in>>a>>b;
    out<<a+b<<endl;
    return 0;
}
