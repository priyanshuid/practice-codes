#include <stdio.h>
#include <iostream>
#define MAX_CANDIDATE 8
using namespace std;
bool finished= false;
void construct_candidate(int ar[],int k,int n,int C[],int *ncandidate);
void is_a_solution(int ar[],int k,int n);
void processSolution(int ar[],int k,int n);
void backtrack(int ar[],int n,int k)
{
    int C[MAX_CANDIDATE];
    int ncandidates;
    int i;
    if(is_a_solution(ar,n,k))
            processSolution(ar,n,k);
    else{
        k++;
        construct_candidate(a,k,n,C,&ncandidates);
        for(i=0;i<ncandidates;i++)
        {
            a[k]=C[i];
            backtrack(ar,n,k);
            if(finished)
                return ;
        }
    }
}
void construct_candidate(int ar[],int k,int n,int C[],int *ncandidate)
{
    bool legal_move;
    for(int i=0;i<n;i++)
    {
        legal_move=true;
        for(int j=1;j<k;j++)
        {
            if(abs(k-j)==abs(ar[i]-i))
                legal_move=false;
            if(i==ar[j])
                legal_move=false;
        }
        if(legal_move==true)
            C[*ncandidate]=i;
            *ncandidate++;
    }
}
void is_a_solution(int ar[],int k,int n)
{
    if(k==n)
        return true;
    else
        return false;
}
void processSolution(int ar[],int k,int n)
{
    for(int i=0;i<n;i++)
        cout<<ar[i]<<" ";
    cout<<endl;
}
int main()
{
    int ar[10];
    backtrack(ar,8,0);
    return 0;
}
