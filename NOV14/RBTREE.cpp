#include <bits/stdc++.h>
using namespace std;
int lca(int a, int b){
	char *str1= new char[10000];
	char *str2= new char[10000];
	int count1=0;
	int count2=0;
	while(a>0){
		char k= a%2 + '0';
		str1[count1++]= k;
		a= a/2;
	}
	count1--;
	
	while(b>0){
		char k= b%2 + '0';
		str2[count2++]= k;
		b=b/2;
	}
	count2--;
	
	string str="";
	while(count1 >= 0 && count2 >=0){
		if(str1[count1]==str2[count2]){
			str=str1[count1]+str;
			count1--;
			count2--;
		}else break;
		
	}
	int lca_num=0;
	int i=0;
	while(i<str.length()){
		if(str.at(i)=='1'){
			lca_num += (int)pow(2, i);
		}
		i++;
	}
	return lca_num;
}
int main(){
	int n;
	cin>>n;
	int flag=0;
	while(n--){
		
		char *str= new char[3];
		int a, b;
			scanf("%s", str);

		if(strcmp(str, "Qi")==0){
			if(flag==1) flag=0;
			else flag=1;
			continue;
		}
		scanf("%d %d", &a, &b);
		int lca_num= lca(a, b);
		if(strcmp(str, "Qr")==0){
			int ha= log2(a)+1;
			int hb= log2(b)+1;
			int hlca= log2(lca_num)+1;
			int ra, rb, rlca;
			if(flag==0){
				ra= ha/2;
				rb= hb/2;
				rlca= hlca/2;
				if(hlca%2==0){
					cout<<ra+rb- 2*rlca +1<<endl;
				}else {
					cout<<ra+rb- 2*rlca<<endl;
				}
				
			}else if(flag==1){
				if(hlca%2==0)rlca= hlca/2;
					else rlca= hlca/2 +1;
				if(ha%2==0)ra= ha/2;
					else ra=ha/2+1;
				if(hb%2==0)rb= hb/2;
					else rb=hb/2+1;
				if(hlca%2!=0)
					cout<<ra+rb- 2*rlca+1<<endl;
				else cout<<ra+rb - 2*rlca<<endl;
			}
		}else{
			int ha= log2(a)+1;
			int hb= log2(b)+1;
			int hlca= log2(lca_num)+1;
			int ba, bb, blca;
			if(flag==0){
				if(hlca%2==0)blca= hlca/2;
					else	blca= hlca/2+1;
				if(ha%2==0)ba= ha/2;
					else ba=ha/2+1;
				if(hb%2==0)bb= hb/2;
					else bb=hb/2+1;
				if(hlca%2!=0)
					cout<<ba+bb- 2*blca+1<<endl;
				else cout<<ba+bb-2*blca<<endl;
			}else{
				ba= ha/2;
				bb= hb/2;
				blca= hlca/2;
				if(hlca%2==0)
				cout<<ba+bb-2*blca+1<<endl;
				else cout<<ba+bb-2*blca<<endl;
			}
		}
	}
}