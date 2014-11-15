#include<stdio.h>
#include <memory.h>
inline long FAST_IO() 
{
	//getchar_unlocked();
	long xxxx;
	char ch;
	int Negativity=0;
	while (((ch=getchar_unlocked()) < 48 || ch > 57) && ch != '-');
	xxxx=0;
	if (ch == '-') Negativity=1;
	else xxxx = ch-48;
	while ((ch=getchar_unlocked()) >= 48 && ch <= 57) xxxx=xxxx*10+ch-48;
	if (Negativity) return -xxxx;
	else return xxxx;
}           
int main()
{
   
   long T,N,arr[100000],i,h[100000],p,start,end,j,sas=0,r,s,k,count=0,temp=0,naruto; 
  static long m[201][10];
  
   long long sum=0; 
   T=FAST_IO();
   while(T--)
   {
       N=FAST_IO();
       sum=0;end=N-2;start=1;sas=0;
       memset(m,0,sizeof(m[0][0])*201*10);
       for(i=0;i<N;i++){               
        arr[i]=FAST_IO();
         if(i==0)continue;
         h[i-1]=arr[i]-arr[i-1];
         }
      
       for(i=0;i<N-1;i++)
       {
          if(h[i]<0)
           p=100-h[i];
           else
           p=h[i];
         //  m[p][1]=i;
        //  if(m[p][1]==-1)m[p][1]=i;
          if(m[p][0]==0)
          {
              m[p][0]++; 
              sas++;
              m[p][1]=i;
              start=1;         
          }
          else
          {
              r=m[p][0];
              s=m[p][1];
           
              temp=1000000;
             // printf("%lld\n",r);
             while(1)
             {
                 for(j=i+1,count=1;j<N-1;j++,count++)
                 {
                     if(h[j]!=h[s+count])break;              
                 }
                r--;
                if(r==0){if(count<temp)
                    temp=count;
                    start=temp;
                    break;}
                else
                {
                    if(count<temp)
                    temp=count;
                  s=m[p][m[p][0]+1-r];
                }
                             
            //  m[p][1]=i;   
             }
             if(m[p][0]==1)
             m[p][0]++; 
             m[p][m[p][0]]=i;
          }
          sum=sum+(end-start+1);
          end--;
          //m[p][0]++;                
       } 
       sum=sum+sas; 
       printf("%lld\n",sum%1000000009);
  }
  return 0;
}     
