#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    string str;
    for(int t1=0;t1<t;t1++)
    {
        cin>>str;
        int noo=0 , noc=0;
        int i=1 , count=0;
        if(str.at(0)=='>')
        {
            cout<<0<<endl;
            continue;
        }
        while(i<str.length() && noc<=noo)
        {
            if(str.at(i)=='<')
                noo++;
            else { noc++ ; count++;}
            i++;
        }
        cout<<count*2<<endl;
    }
    return 0;
}
