#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
    int k=1;
    vector <int> fact[101];
    fact[k].push_back(1);
    int ii=2;
    int count=3;
    for(int b=2; b <=100; b++) {
        int p=0;
        vector <int> aux[3];
        while(ii!=0)
        {
            int k=ii%10;
            ii=ii/10;
            int carry = 0;
            for(int j=0;j<p;j++){
                aux[p].push_back(0);
            }
            if(k==0)
            {
                p++;
                continue;
            }
            for(int j=0;j != fact[b-1].size();j++){
                    aux[p].push_back((carry + k*fact[b-1][j])% 10);
                    carry = (carry+k*fact[b-1][j]) /10;
            }
            if(carry != 0)
                aux[p].push_back(carry);
            p++;
        }
        int carry=0;
        int maxm= max(aux[0].size(), aux[1].size());
        maxm = max(maxm , (int)aux[2].size());
        int j;
        for(j=0;j<maxm;j++){
            int sum =carry;
            for(int k=0;k<3;k++){
                if(!aux[k].empty() && aux[k].size()>j)
                    sum += aux[k][j];
            }
            carry = sum/10;
            sum = sum%10;
            fact[b].push_back(sum);
        }
        if(carry !=0)
        fact[b].push_back(carry);
        ii=count;
        count++;
    }
    int t;
   cin>>t;

    for(int t1=0;t1<t;t1++){
        int n;
        cin>>n;
        if(n==0) cout<<1<<endl;
        for(int i=fact[n].size()-1;i>=0;i--)
            cout<<fact[n][i];
        cout<<endl;
    }
}
