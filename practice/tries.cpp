#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
class node
{
    public:
        node *ar[26];
        char a;
        bool is_end;
        no_of_words;
};
void inser
int main()
{
    int n;
    cin>>n;
    node root=null;
    initialise(root);
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        insert(root,str,str.length());
    }
    int q,c;
    cin>>c;
    int count=0;
    for(int i=0;i<c;i++)
    {
        string pre;
        cin>>pre;
        prefix_match(root,pre,pre.length());
    }
    cin>>q;
    for(int i=0;i<q;i++)
    {
        string stf;
        cin>>stf;
        search(root,str,str.length());
    }
    return 0;
}
