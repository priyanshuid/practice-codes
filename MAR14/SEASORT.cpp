#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ar[n];
    vector <int> soln1;
    for(int i=0;i<n;i++)
        scanf("%d",&ar[i]);
    int count=0;
    for(int i=1;i<n-1;i++)
    {

        while(ar[i+1]<ar[i])
        {
            count++;
            int temp=ar[i];
            ar[i]=ar[i+1];
            ar[i+1]=temp;
            soln1.push_back(i);
        }
    }
    cout<<count<<endl;
    for(int i=0;i<soln1.size();i++)
    {
        printf("%d %d\n",soln1[i]+1, soln1[i]+2);
    }
    return 0;
}
