/**
Tries are usually used to implement dictionaries.
The following code has functionality to insert and lookup in a trie
Tries are powerfull data structures,often used in programming competitions and development.
Time complexity of the search and insert is-
Insert and Search - Theta(m) (m- length of the string to be searched).
Time to construct the trie - Theta(n) ( n= Sigma(lengths of all strings) ).
Recursive definition of the trie.
**/

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <cstring>
#define null NULL
using namespace std;
/**
Node structure used in the trie
Every node has number of children equal to the size of the universe of the character set.
We have assumed that we have only small characters 'a' to 'z'.
**/
struct node {

    char ch;
    node *child[27];
};
//Procedure to insert a node recursively, character by charachter,
// if node correspoding to a character is present, the remaining string is appended as the new branch.
void insert(node **root, string str){
    if((*root) == null){
        //case where the node corresponding to this character is absent
        //create a node corresponding to this character.
        (*root) = new node();
        (*root)->ch= str.at(0);
        if((*root)->ch == '$') return;
        else{
               if(str.at(1)!='$') insert(&((*root)->child[str.at(1)-97]), str.substr(1));
               else insert(&((*root)->child[26]), str.substr(1));
            }
    }else{
    //case where we have a node corresponding to this node
    //we simply call the insert function recursively for remaining substring
            if(str.at(1)!='$') insert(&((*root)->child[str.at(1)-97]), str.substr(1));
            else insert(&((*root)->child[26]), str.substr(1));
    }
}
// function to search for a string in trie//
bool find(node *root, string str){
    if(root == null){
        return false;
    }else if(str == "$") {
        if(root->child[26] != null) return true;
        else    return false;
    }

    else {
            return find(root->child[str.at(0)-97], str.substr(1));
    }
}
//test run
int main(){
    int n;
    cin>>n;
    node *root=NULL;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        str+= '$';
        str = '/'+str;
        insert(&root, str);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        string str;
        cin>>str;
        str=str+'$';
        bool ans=find(root, str);
        cout<<ans<<endl;
    }
    return 0;
}
