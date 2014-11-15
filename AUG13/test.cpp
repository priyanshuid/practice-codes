#include<iostream>
using namespace std;
 
struct st{
    int wi;
    float p;
} arr[101];
int main()
{
    int t,w,n,i,Wt,half;
    float sum,p1;
    cin>>t;
    while(t--)
    {   
        sum=0.0;
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>arr[i].wi;
        for(i=1;i<=n;i++)
            {
                cin>>p1;
                arr[i].p=p1/100;
            }
        //cout<<arr[2].wi<<endl;
        Wt = n*(n+1)/2;
        float k[n+1][Wt+1];
        //cout<<"hello ";
         for(i=0;i<=Wt;i++)
          { 
             k[0][i]=0;
          }
        for(i=1;i<=n;i++)
            if(arr[i].wi)
            {    k[0][arr[i].wi]=arr[i].p; break;}
        for(i=0;i<=n;i++)
            cout<<k[0][i]<<" ";
        for(i=1;i<=n;i++)
            for(w=0;w<=Wt;w++){
             if(w>=arr[i].wi)
                k[i][w] = k[i-1][w-arr[i].wi]*arr[i].p + k[i-1][w]*(1-arr[i].p);
            else k[i][w]=k[i-1][w];
            }
for(i=0;i<=n;i++)
    {cout<<endl;
        for(w=0;w<=Wt;w++)
            cout<<" "<<(float)k[i][w];
     }
     half= (int)(Wt/2+0.5);
     cout<<"half "<<half<<endl;
        for(i=half;i<Wt;i++)
            sum+=k[n][i];
        cout<<sum<<endl;
    }
    return 0;
} 
