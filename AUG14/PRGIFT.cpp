#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int t1=0;t1<t;t1++){
        int n,k;
        scanf("%d %d", &n, &k);
        int count=0;
        for(int i=0;i<n;i++){
            int temp;
            scanf("%d", &temp);
            if(temp%2==0)
                count++;
        }
        if(k==0){
            if(count==n)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
            continue;
        }
        if(count>=k)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
