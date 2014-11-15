#include <bits/stdc++.h>
#define MAXN 50001
#define LOGMAX 17
using namespace std;

struct entry{
	int nr[2];
	int p;
}L[MAXN];
int stp;
int sortIndex[LOGMAX][MAXN];
bool compare(const entry &e1, const entry &e2){
	return e1.nr[0]==e2.nr[0]?(e1.nr[1]<e2.nr[2]?1:0):(e1.nr[0]<e2.nr[0]?1:0);
}

void createSuffixArray(string str){
	int N= str.length();
	for(int i=0;i< str.length();i++)
		sortIndex[0][i]= str.at(i)-1;
	stp=1;
	for(int cnt=1; cnt>>1 < N; stp++ , cnt<<=1){

		for(int i=0;i<N;i++){
			L[i].nr[0]=sortIndex[stp-1][i];
			L[i].nr[1]=(i+cnt <N)?sortIndex[stp-1][i+cnt]:-1;
			L[i].p=i;
		}
		sort(L, L+N, compare);
		for(int i=0;i<N;i++){
			sortIndex[stp][L[i].p]=i>0 && L[i].nr[0]== L[i-1].nr[0] && L[i].nr[1]==L[i-1].nr[1]? sortIndex[stp][L[i-1].p]:i;
		}
	}
}
int createLCPArray(int x ,int y, int N){
	int val=0;
	for(int k= ceil(log(N))-1; k>=0 && x<N && y< N;k--){
		if(sortIndex[k][x]==sortIndex[k][y]){
			val+= 1<<k;
			x+= 1<<k;
			y+= 1<<k;
		}
	}
	return val;
}
int main(){
	int t;
	cin>>t;
	for(int i=0;i< t;i++){
		string str;
		cin>>str;
		memset(sortIndex, 0 , sizeof(sortIndex));
		createSuffixArray(str);
		int N= str.length();
		for(int i=0;i<=log(N);i++){
			for(int j=0;j<N;j++)
				cout<<sortIndex[i][j]<<" ";cout<<endl;
		}
		int val= 0;
		for(int i=1;i< str.length();i++){
			if(i==0){
				val+=N-1- sortIndex[stp-1][i]+1;
			}else
			val+=N-1- sortIndex[stp-1][i]-createLCPArray(i-1,i, str.length());
			
		}
		cout<<val<<endl;
	}
	return 0;
}