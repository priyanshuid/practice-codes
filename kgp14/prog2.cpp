#include <bits/stdc++.h>
#define MAX 1000000000
using namespace std;
pair <double , double> p0;
double dist(pair<double , double> p1, pair<double, double> p2)
{
   return  sqrt((p1.first-p2.first)*(p1.first-p2.first)+ (p1.second- p2.second)*(p1.second-p2.second));
}
bool compare(const pair <double, double> &p1, const pair <double, double> &p2){
    return dist(p1, p0) < dist(p2, p0);
}
bool compare2(const pair <double, double> &p1, const pair <double, double> &p2){
    if(p1.first< p2.first) return true;
    else if(p1.first == p2.first){
        return p1.second < p2.second;
    }
    return false;
}
bool compare3(const pair <double, double> &p1, const pair <double, double> &p2){
    if(p1.second < p2.second) return true;
    else if(p1.second == p2.second){
        return p1.first < p2.first;
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    for(int t1=0;t1<t;t1++){
        int n;
        cin>>n;
        pair <double, double> ar[n];
        for(int i=0;i<n;i++){
            double a, b;
            cin>>a>>b;
            ar[i].first = a, ar[i].second=b;
        }
        p0.first=ar[0].first;
        p0.second=ar[0].second;
        sort(ar, ar+n, compare);
        double minDist=MAX;
        for(int i=0;i< n-2;i++){
            double temp= dist(ar[i], ar[i+1])+dist(ar[i+1], ar[i+2])+dist(ar[i], ar[i+2]);
            if(temp < minDist)  minDist=temp;
        }
        sort(ar, ar+n, compare2);
        for(int i=0;i< n-2;i++){
            double temp= dist(ar[i], ar[i+1])+dist(ar[i+1], ar[i+2])+dist(ar[i], ar[i+2]);
            if(temp < minDist)  minDist=temp;
        }
        sort(ar, ar+n, compare3);
      //  for(int i=0;i<n;i++) cout<<ar[i].first<<" "<<ar[i].second<<" ";
       // cout<<endl;
        for(int i=0;i< n-2;i++){
            double temp= dist(ar[i], ar[i+1])+dist(ar[i+1], ar[i+2])+dist(ar[i], ar[i+2]);
            if(temp < minDist)  minDist=temp;
        }
        printf("Case %d: %0.9lf\n",t1+1,minDist);
    }
    return 0;
}
