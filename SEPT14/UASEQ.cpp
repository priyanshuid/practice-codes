#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
int main()
{
    int n,k;
    scanf("%d %d", &n, &k);
    int ar[n+1];
    int diff[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", ar+i);
        if(i==0)
            continue;
        diff[i]=ar[i]- ar[i-1];
    }

    return 0;
}
