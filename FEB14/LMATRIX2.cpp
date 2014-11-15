#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int p[n][m];
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            scanf("%d",&p[i][j]);
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            {scanf("%d",&a[i][j]);
            if(a[i][j]!=0)
                count++;
                }
    }
    cout<<count<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            if(a[i][j]!=0)
                printf("%d %d %d %d %d\n",i+1,j+1,i+1,j+1,p[i][j]-a[i][j]);
    }
    return 0;
}
