#include <iostream>
#include <string>
#include <cstring>
using namespace std;
typedef struct node node;
struct node
{
    char a;
    node *child[27];
};
void insert_string(string mtch , node **root)
{
    if((*root)->child[mtch.at(0)-65]==NULL)
    {
        node *n1= new node();
        (*n1).a=mtch.at(0);
        if(mtch.at(0)=='$')
        {
            (*root)->child[26]=n1;
            return ;
        }
        else
            (*root)->child[mtch.at(0)-65]=n1;
        insert_string(mtch.substr(1), &n1);
    }
    else
    {
        insert_string(mtch.substr(1), &((*root)->child[mtch.at(0)-65]) );
    }
}
bool present(string mtch, node *root)
{
    if((root)->child[26]!=NULL && mtch==" ")
        return true;
    else if(mtch==" ")
        return false;
    if((root)->child[mtch.at(0)-65]==NULL)
        return false;
        present(mtch.substr(1), ((root)->child[mtch.at(0)-65]));
}
void print(node *root)
{
    cout<<root->a<<" ";
    for(int i=0;i<26;i++)
    {
        if(root->child[i]!=NULL)
        print(root->child[i]);
    }
    return;
}
int main()
{
    int n,q;
    cin>>n>>q;
    node *root=new node();
    root->a='@';
    string str;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        str+="$";
        insert_string(str, &root);
    }
    print(root);
    for(int i=0;i<q;i++)
    {
        cin>>str;
        str+=" ";
        bool val=present(str,root);
        if(val==true)
            cout<<"PRESENT"<<endl;
        else cout<<" NOT PRESENT"<<endl;
    }
    return 0;
}
