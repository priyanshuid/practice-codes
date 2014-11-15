#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
string binary_convert(int n)
{
    string str="";
    while(n!=0)
    {
        if(n%2==0)
        str='0'+str;
        else
        str='1'+str;
        n=n/2;
    }
    return str;
}
string ancestor(string a, string b)
{
    a=a+'$';
    b=b+'$';
    char a1=a.at(0);
    char b1=b.at(0);
    string ans="";
    int i=0,j=0;
    while((a1!='$' && b1!='$') && (a1==b1))
    {
        ans+=a1;
        i++;
        j++;
        a1=a.at(i);
        b1=b.at(j);
    }
    return ans;
}
int distance_from_ancestor(string a, string anstr)
{
    return a.length()-anstr.length();
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        string a1, b1;
        a1=binary_convert(a);
        b1=binary_convert(b);
        string val=ancestor(a1, b1);
        int d1=distance_from_ancestor(a1, val);
        int d2=distance_from_ancestor(b1, val);
        printf("%d\n",d1+d2);
    }
    return 0;
}
