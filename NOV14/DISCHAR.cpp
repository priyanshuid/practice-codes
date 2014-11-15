#include <bits/stdc++.h>
using namespace std;
char *ar= new char[100005];
int main(){
	int t;
	cin>>t;
	while(t--){
		scanf("%s", ar);
		int flag=0;
		int hash[26];
		memset(hash, 0, sizeof(hash));
		int n= strlen(ar);
		int index;
		for(int i=0;i<n;i++){
			hash[ar[i]-97]=1;
		}
		int count=0;
		for(int i=0;i<26;i++)if(hash[i]==1)count++;
		cout<<count<<endl;
	}
	return 0;
}