/*
ID: priyanshuid
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a,b;
    fin >> a >> b;
    int prod1=1,prod2=1;
    for(int i=0;i<a.length();i++)
    {
    	char d=a.at(i);
    	int j=(int)d-64;
    	prod1*=j;
    }
    for(int i=0;i<b.length();i++)
    {
    	char d=b.at(i);
    	int j=(int)d-64;
    	prod2*=j;
    }
    prod1=prod1%47;
    prod2=prod2%47;
    if(prod1==prod2)
    	fout<<"GO"<<endl;
    else
    	fout<<"STAY"<<endl;
    return 0;
}
