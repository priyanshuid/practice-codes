#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int t,m,n,i;
    scanf("%d",&t);
    for(int t1=0;t1<t;t1++)
    {
        scanf("%d",&m);
        vector <int> a;
        for(i=0;i<m;i++)
            {
            	int g;
				scanf("%d",&g);
				a.push_back(g);
			}
 
        scanf("%d",&n);
        vector <int> b;
        for(i=0;i<n;i++)
    	{
    			int g;
				scanf("%d",&g);
				b.push_back(g);
 		}
        int count=0;
 
        for(int j=0;j<m;j++)
            {
               int v= b.at(j);
                 if (std::binary_search (a.begin(), a.end(), v))
                      z--;
 
                      else
                      ++count;      }
 
                    int q=abs(m-n);
                    cout<<q<<endl;
 
    }
    return 0;
}
