#include <bits/stdc++.h>
using namespace std;
char *str = new char[100005];
bool isPalindrome(int a,int b){
	int inc=a, dec=b;
	while(inc <= (b+a)/2){
		if(str[inc++] != str[dec--])
			return false;
	}
	return true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		scanf("%s", str);
		int n= strlen(str);
		if(isPalindrome(0, n-1)){
			cout<<"YES"<<endl;
		}
		else{
				int flag=0;
				int inc=0, dec=n-1;
				while(inc < n/2){
					if(str[inc] != str[dec]){
						
						int inc1=inc+1;
						int dec1=dec;

						int inc2=inc;
						int dec2=dec-1;
						
						if(isPalindrome(inc1, dec1) || isPalindrome(inc2, dec2))
						{	flag=1;  }
						break;		

					}else {
						inc++;
						dec--;
					}
				}
			if(flag==1) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}