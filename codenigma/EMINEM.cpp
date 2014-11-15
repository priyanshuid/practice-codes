#include <iostream>
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <fstream>
using namespace std;
int table[1000005][21];
int cross[21][21];
int maxm;

int true_allowed(int ar[],int m,int i);
void backtrack(int solution_vector[], int m,int i)
{
    if(i==m+1)
    {
        int count=0;
        for(int j=1;j<=m;j++)
        {
            if(solution_vector[j]==1)
                count++;
            //    cout<<solution_vector[j];
        }
       // cout<<endl;
        if(count>maxm)
            maxm=count;
        return;
    }
    else
    {
        if(true_allowed(solution_vector,m,i)==1)
        {
            solution_vector[i]=1;
            backtrack(solution_vector,m,i+1);
        }
        solution_vector[i]=0;
        backtrack(solution_vector,m,i+1);
    }
}
int true_allowed(int solution_vector[],int m,int i)
{
    for(int j=1;j<i;j++)
    {
        if(solution_vector[j]==1 && cross[i][j]==1)
            return 0;
    }
    return 1;
}
int main()
{
    ifstream in("eminem_input.txt");
    int n, m;
    in>>n>>m;
    memset(table, 0 , sizeof(table));
    for(int i=1;i<=m;i++)
    {
            int k;
            in>>k;
            for(int j=0;j<k;j++)
            {
                int g;
                in>>g;
                table[g][i]=1;
            }
    }
    memset(cross, 0,sizeof(cross));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(table[i][j]==1)
            {
                for(int k=j;k<=m;k++)
                {
                    if(table[i][k]==1)
                        cross[j][k]=cross[k][j]=1;
                }
            }
        }
    }
    int solution_vector[m+1];
    backtrack(solution_vector,m,1);
    cout<<maxm<<endl;
    return 0;
}
