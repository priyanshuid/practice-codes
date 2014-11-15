#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++){
		int n,m;
		cin>>n>>m;
		int ar[n];
		int max=-1;
		for(int i=0;i<n;i++){
			scanf("%d", &ar[i]);
			if(ar[i]>max) max= ar[i];
		}
		for(int i=0;i<n;i++){
			m= m-max+ar[i];
		}
		if(m%n==0)	cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}