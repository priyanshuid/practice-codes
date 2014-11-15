#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <memory.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++)
    {
        string s1,s2;
        cin>>s1>>s2;
        int f1[62],f2[62];
        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f2));
        for(int i=0;i<s1.length();i++)
        {
            if(s1.at(i)>='a' && s1.at(i)<='z')
                f1[(int)s1.at(i)-97]++;
            else if(s1.at(i)>='A' && s1.at(i)<='Z')
                f1[(int)s1.at(i)-65+26]++;
            else   f1[(int)s1.at(i)-48+52]++;
        }
        for(int i=0;i<s2.length();i++)
        {
            if(s2.at(i)>='a' && s2.at(i)<='z')
                f2[(int)s2.at(i)-97]++;
            else if(s2.at(i)>='A' && s2.at(i)<='Z')
                f2[(int)s2.at(i)-65+26]++;
            else f2[(int)s2.at(i)-48+52]++;

        }
        int sum=0;
        for(int i=0;i<62;i++)
            sum+=min(f1[i],f2[i]);
        cout<<sum<<endl;
    }
    return 0;
}
