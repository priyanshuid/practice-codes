/*
ID: priyanshuid
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream in("ride.in");
    ofstream out("ride.out");
    string a,b;
    in>>a>>b;
    int v1=1,v2=1;
    for(int i=0;i<a.length();i++){
        v1= (v1* (a.at(i)-64));
    }
    for(int i=0;i<b.length();i++){
        v2= (v2* (b.at(i)-64));
    }
    if(v1%47 == v2%47)out<<"GO"<<endl;
    else out<<"STAY"<<endl;
    return 0;
}
