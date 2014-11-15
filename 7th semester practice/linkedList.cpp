#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

struct node{
    int val;
    node *next;
};

int main(){

    int n;
    cin>>n;
    node *head = new node;
    head->val = 0;
    head->next= NULL;
    node *temp=head;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(i==0){
            head->val=val;
            head->next=NULL;
            temp=head;
        }else{
            node *newNode= new node;
            newNode->val =val;
            temp->next=newNode;
            newNode->next=NULL;
            temp= newNode;
        }
    }
    node *temp1=head;
    while(temp1 !=NULL){
        cout<<temp1->val;
        temp1=temp1->next;
    }
    return 0;
}
