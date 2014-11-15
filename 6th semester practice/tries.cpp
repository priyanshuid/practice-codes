//Assuming that our trie takes charachter with ASCII Value from 65 to 90 and char '$' is the string terminator
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <vector>
using namespace std;
class node
{
    public:
    node *child[27];
};
node initialise(bool ab)
{
    node n1;
    return n1;
}
void insert_string(string mtch, node *root)
{
   cout<<"A";
    if(mtch==" ")
        return;

    if(root->child[mtch.at(0)-65]==NULL)
    {
        if(mtch.at(0)!='$')
        {
           // node n1=initialise('$');
            root->child[26]=new node();
        }
        else
        {
           // node n1=initialise(mtch.at(0));
            root->child[mtch.at(0)-65]=new node();
        }
    }
    insert_string(mtch.substr(1), root->child[mtch.at(0)-65]);
}
bool present(string mtch, node *root)
{
    if(root->child[26]!=NULL && mtch==" ")
        return true;
    if(root->child[mtch.at(0)-65]==NULL)
        return false;
    else
        present(mtch.substr(1), root->child[mtch.at(0)-65]);
}
int main()
{
    int n;
    cin>>n;
    string str[n];
    node root;
    for(int i=0;i<n;i++)
    {
        cin>>str[i];

        str[i]=str[i]+"$ ";
        cout<<str[i]<<endl;
        insert_string(str[i],&root);
    }
    return 0;
}
