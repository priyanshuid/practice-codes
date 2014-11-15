#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
bool compare(const pair<int, int> &p1,const pair<int, int> &p2){
    if(p1.first < p2.first) return true;
    else if(p1.first == p2.first){
        return p1.second < p2.second;
    }
    return false;
}
int compareForSearch(const void *p1, const void *p2){
    if((*(pair<int,int> *)p1).first == (*(pair<int, int>*)p2).first && (*(pair<int, int>*)p1).second == (*(pair<int,int>*)p2).second)
      return 0;
    else if((*(pair<int,int> *)p1).first < (*(pair<int, int>*)p2).first)
    {
        return -1;
    } else if((*(pair<int, int>*)p1).first == (*(pair<int,int>*)p2).first && (*(pair<int, int>*)p1).second < (*(pair<int,int>*)p2).second) return -1;
    return 1;
}
bool search(pair<int, int> point[],int x,int y,int n)
{
    int start = 0;
    int end = n-1;
    while(start<=end)
    {
        int mid = (start + end)/2;
        if(point[mid].first==x && point[mid].second == y) return true;
        else if( point[mid].first==x )
        {
            if( point[mid].second > y) end = mid - 1;
            else start = mid + 1;
        }
        else if(point[mid].first > x) end = mid - 1;
        else start = mid + 1;
    }
    return false;
}
int main(){
    int n;
    scanf("%d", &n);
    pair <int, int> points[n];
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d %d", &a, &b);
        points[i] = pair<int, int>(a,b);
    }
    sort(points, points+n, compare);
    int minPoints=2;
    int flag=0;
    if(n==0){
        cout<<4<<endl;
    }
    else if(n==1){
        cout<<3<<endl;
    }
    else if(n==2){
        cout<<2<<endl;
    }
    else{
        for(int i=0;i<n && flag==0;i++){
            for(int j=0;j<n && flag==0 && j!=i;j++){
                int curPoints=2;
                pair <int, int> a = points[i];
                pair <int, int> b = points[j];
                int x1= a.first, x2=b.first;
                int y1=a.second, y2=b.second;
                int twiceXc=x1+x2;
                int twiceYc=y1+y2;
                int twiceXd=x1-x2;
                int twiceYd=y1-y2;

                pair <int, int> p3= pair<int,int> (a.first+ b.second -a.second, a.second - b.first+ a.first);
                pair <int, int> p4= pair<int,int> (b.first+ b.second -a.second, b.second - b.first+ a.first);
             //   cout<<p3.first << " "<<p3.second<<endl;
           //     cout<<p4.first << " "<<p4.second<<endl;
               // if(bsearch(&p3, points,n , sizeof(pair<int, int>), compareForSearch)!=NULL)
                 //   curPoints--;
               // if(bsearch(&p4, points,n , sizeof(pair<int, int>), compareForSearch)!=NULL)
                 //   curPoints--;
              //  if(curPoints == 0){
                //    cout<<a.first<<" "<<a.second<<endl;
                  //  cout<<b.first<<" "<<b.second<<endl;
                    //cout<<p3.first<<" "<<p3.second<<endl;
                 //   cout<<p4.first<< " "<<p4.second<<endl;
               // }
               if(search(points, p3.first, p3.second, n)) curPoints--;
               if(search(points, p4.first, p4.second, n)) curPoints--;
                if(minPoints > curPoints) minPoints=curPoints;
                if(minPoints == 0){
                    flag=1;
                }
            }
        }
        cout<<minPoints<<endl;
    }
    return 0;
}
