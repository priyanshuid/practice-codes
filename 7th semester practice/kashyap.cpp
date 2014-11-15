#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <fstream>
struct entry {

    int num;
    char ch;
};
using namespace std;
int main(){
    ifstream in("input.txt");
    vector<entry> entries;
    for(int i=1;i<=550001;i++){
        int k,n;
        char bogus_char;
        in>>k;
        in>>bogus_char;
        in>>n;
        in>>bogus_char;
        char ch;

        in>>ch;
        in>>bogus_char;
        in>>bogus_char;
        in>>bogus_char;
        entry e1;
        e1.num=n;
        e1.ch=ch;
        entries.push_back(e1);
    }
    in.close();
    double s=0, b=0, AWS=0;
    for(int i=0;i<550001;i++){
        if(entries[i].ch == 's'){
            s+=entries[i].num;
        }else if(entries[i].ch=='b'){
            b+=entries[i].num;
        }
    }
    cout<<s << " "<< b<<endl;
    AWS= sqrt( 2 * ( s+b+10)* log(1 + s/ ( b+10))  - s);
    cout<<AWS;
    return 0;
}
