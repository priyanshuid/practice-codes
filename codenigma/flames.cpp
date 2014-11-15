#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <vector>
typedef struct node node;
using namespace std;
struct node
{
    char a;
    node *next;
};
int main()
{

    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++)
    {
    node *f=new node();
    node *l=new node();
    node *a=new node();
    node *m=new node();
    node *e=new node();
    node *s=new node();
    f->a='f';
    f->next=l;
    l->a='l';
    l->next=a;
    a->a='a';
    a->next=m;
    m->a='m';
    m->next=e;
    e->a='e';
    e->next=s;
    s->a='s';
    s->next=f;
    int hash[26];
    string a1,b;
    cin>>a1>>b;
    string str=a1+b;
    memset(hash, 0 ,sizeof(hash));
    for(int i=0;i<str.length();i++)
        hash[str.at(i)-97]=1;
    int count=0;
    for(int i=0;i<26;i++)
        {if(hash[i]==1)
        count++;}
    node *n=f;
    while(n->next!=n)
    {
        for(int i=1;i<count-1;i++)
        {
            n=n->next;
        }
        n->next=n->next->next;
        n=n->next;
    }
    //cout<<n->a<<endl;
/*    LOVE
A- AFFECTION
M- MARRIAGE
E- ENDEARMENT
S- SISTERHOOD*/
    if(n->a=='f')
        cout<<"FRIENDSHIP"<<endl;
    else if(n->a=='a')
        cout<<"AFFECTION"<<endl;
    else if(n->a=='m')
        cout<<"MARRIAGE"<<endl;
    else if(n->a=='l')
        cout<<"LOVE"<<endl;
    else if(n->a=='e')
        cout<<"ENDEARMENT"<<endl;
    else cout<<"SISTERHOOD"<<endl;
    }
    return 0;
}
