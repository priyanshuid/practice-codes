#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n!=0){
        string str;
        cin>>str;
        int r=str.length()/n;
        int c=n;
        char ar[r][c];
        int k=0;
        for(int i=0;i<r;i++)
        {
                if(i%2 == 0){
                    for(int j=0;j<c;j++){
                        ar[i][j]=str.at(k++);
                    }
                }else{
                    for(int j=0;j<c;j++){
                        ar[i][c-j-1]=str.at(k++);
                    }
                }
        }
        for(int j=0;j<c;j++)
        {
            for(int i=0;i<r;i++)
                cout<<ar[i][j];
        }
        cout<<endl;
        cin>>n;
    }
    return 0;
}
