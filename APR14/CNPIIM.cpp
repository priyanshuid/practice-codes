#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <memory.h>
using namespace std;
int val[1562505];
int main()
{
    int t;
    ofstream out("ans.txt");
    memset(val, 0 ,sizeof(val));
    for(int t1=1;t1<=2500;t1++)
    {
        int n=t1;
        long long sum=0;
        for(int i=1;i<=n/2;i++)
        {
            int k=i*(n-i);
            int mul_fact;
            if(i==n-i)
                mul_fact=1;
            else mul_fact=2;

            int count_total=0;
            for(int j=1;j<k;j++)
            {

                if(val[j]==0)
                {
                   int count=0;
                   for(int x1=1;x1<=sqrt(j);x1++)
                   {
                        if(j%x1==0)
                        {
                            if(j/x1==x1)
                                count++;
                            else count=count+2;
                        }
                   }
                   val[j]=count;
                   count_total+=count;
                }
                else count_total+=val[j];
            }
            sum+=count_total*mul_fact;
        }
        out<<sum<<",";
        printf("%d %lld\n", t1, sum);
        //n<<t1<<" "<<sum<<endl;
    }
    return 0;
}
