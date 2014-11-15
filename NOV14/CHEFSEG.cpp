#include <bits/stdc++.h>
using namespace std;
long long pow(long long a, long long b){

	if(b==0) return 1;
	else if(b==1) return a;
	int temp= a*a;
	if(b%2==0) {
		return pow(temp, b/2);
	}else return a*pow(temp, b/2);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		
		long long x, k;
		cin>>x>>k;

		long long v= log2(k);
		long long vv= pow(2, v+1);

		double vvv = (double)x/vv;

		long long vvvv = pow(2, v)-1;

		long long vvvvv= k- vvvv; 

		double ans = vvv + (vvvvv-1)*2*vvv;

		printf( "%.10lf\n", ans);

	}
	return 0;
}