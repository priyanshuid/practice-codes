#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <vector>
#define ll long long
#define sq(x) x*x
using namespace std;
struct point {
	ll x, y;
} P[100000], C[100000], P0;

ll triArea2(point a, point b, point c){
	return a.x*(b.y - c.y) + b.x*(c.y- a.y) + c.x*(a.y - b.y);
}

ll distance2(point a, point b){
	return sq(a.x - b.x) + sq(a.y - b.y);
}

bool compare(const point &a, const point &b){
	ll ar= triArea2(P0, a, b);
	if(ar < 0 )	return false;
	else if( !ar && distance2(P0, b)> distance2(P0, a)) return false;
	return true;
}

int main(){

	int min =0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>P[i].x>>P[i].y;
	for(int i=1;i<n;i++){
		if(P[i].y < P[min].y)  min=i;
		else if(P[i].y == P[min].y){
			if(P[i].x > P[min].x)
				min= i;
		}
	}
	swap(P[0], P[min]);
	P0 = P[0];
	sort(P+1, P+n, compare);
	C[0]=P[0];
	C[1]=P[1];
	C[2]=P[2];
	int total=0;
	for(int i=3, j=3; i<n;i++)
	{
		while(triArea2(C[j-2], C[j-1], P[i])<0) j--;
        C[j++]=P[i];
        total=j;
	}
	cout<<total<<endl;
	for(int i=0;i<total;i++)	cout<<C[i].x<<" "<<C[i].y<<endl;
	return 0;

}
