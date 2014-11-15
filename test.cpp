#include<iostream> 
using namespace std; 
int func(int m,int n,int a[][100] ); 
int main() { 
int m,n,i,j; 
cin>>m>>n; 
int a[m][100]; 
for(i=0;i<m;i++) 
{ 
for(j=0;j<n;j++) 
{ 
a[i][j]=0; 
} 
} 
func(m,n,a); 
} 
int func(int m,int n,int a[][100] ) {
 int i,j; 
for(i=0;i<m;i++) 
{ 
for(j=0;j<n;j++) { 
cout<<a[i][j]; 
 
} 
} 
}
