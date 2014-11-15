#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <math.h>
#define unsigned long long ull
#define EPSILON exp(-15)
using namespace std;
int ar[3][4];
struct point
{
	int x,y;
	point()
	{
		int x1,y1;
		x=x1;
		y=y1;
	}
};
double dist(point a,point b)
{
	int val=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
	double vv=sqrt(val);
	return vv;
}
bool areSame(double d1,double d2)
{
	return fabs(d1 - d2) < EPSILON;
}
bool isOnline(point a1,point a2,point a3)
{
	double d1=dist(a1,a2);
	double d2=dist(a1,a3);
	double d3=dist(a2,a3);
	if(areSame(d1+d2,d3) || areSame(d1+d3,d2) || areSame(d2+d3,d1))
	return true;
	else return false;
}
bool check(double g,double h,double c, point a)
{
	if(a.x*a.x + a.y*a.y + g*a.x + h*a.y + c <0 || areSame(a.x*a.x + a.y*a.y + g*a.x + h*a.y + c,0.0))
	return true;
	else
	return false;
}
void solveDet(point X,point Y,point Z,double &g,double &h,double &c1)
{
		int i,j; 
	/*	for(int i1=0;i1<3;i1++)
		{
			for(int b1=0;b1<4;b1++)
			cout<<a[i1][b1]<<" ";
			cout<<endl;
		}*/
		int a,b,c,d,l,m,n,k,p,q,r,s;
		double D,x1,y1,z1;
		a=X.x;b=X.y;c=1;d=X.x*X.x+X.y*X.y;
		l=Y.x;m=Y.y;n=1;k=Y.x*Y.x+Y.y*Y.y;
		p=Z.x;q=Z.y;r=1;s=Z.x*Z.x+Z.y*Z.y;
		
		D = (a*m*r+b*p*n+c*l*q)-(a*n*q+b*l*r+c*m*p);
	 	x1 = ((b*r*k+c*m*s+d*n*q)-(b*n*s+c*q*k+d*m*r))/D;
 		y1 = ((a*n*s+c*p*k+d*l*r)-(a*r*k+c*l*s+d*n*p))/D;
 		z1 = ((a*q*k+b*l*s+d*m*p)-(a*m*s+b*p*k+d*l*q))/D;
 		g=x1;h=y1;c1=z1;
	
		//	cout<<g<<" "<<h<<"  "<<c1<<endl;
		//} 
}
/*void formDet(point a1,point a2,point a3,int ar[][4])
{
	ar[0][0]=a1.x;ar[0][1]=a1.y;ar[0][2]=1;
	ar[1][0]=a2.x;ar[1][1]=a2.y;ar[1][2]=1;
	ar[2][0]=a3.x;ar[2][1]=a3.y;ar[2][2]=1;
	//if(a1.x==0 && a1.y==0)
	//	ar[0][3]=0;
	//else
		ar[0][3]=(-a1.x*a1.x-a1.y*a1.y);
//	if(a2.x==0 && a2.y==0)
//		ar[1][3]=0;
//	else
		ar[1][3]=(-a2.x*a2.x-a2.y*a2.y);
//	if(a3.x==0 && a3.y==0)
//		ar[2][3]=0;
//	else
		ar[2][3]=(-a3.x*a3.x-a3.y*a3.y);
}*/
int main()
{
	int t;
	scanf("%d",&t);
	for(int t1=0;t1<t;t1++)
	{
			int n;
			scanf("%d",&n);
			point pts[n];
			int count=0;
			double total=n*(n-1)*(n-2)*(n-3)/6;
			for(int i=0;i<n;i++)
				scanf("%d%d",&pts[i].x,&pts[i].y);
			for(int i=0;i<n-2;i++)
			{
				for(int j=i+1;j<n-1;j++)
				{
					for(int k=j+1;k<n;k++)
					{
						
						if(!isOnline(pts[i],pts[j],pts[k]))
						{
							bool k1=false;					
						//	formDet(pts[i],pts[j],pts[k],ar);
							double g,h,c;
							solveDet(pts[i],pts[j],pts[k],g,h,c);
							for(int p=0;p<n;p++)
							{
								
								if(p!=i && p!=j && p!=k)
								{
									k1=check(g,h,c,pts[p]);
									if(k1==true)
									{
									count++;
								//	cout<<pts[i].x<<" "<<pts[i].y<<" "<<pts[j].x<<" "<<pts[j].y<<" "<<pts[k].x<<" "<<pts[k].y<<" "<<pts[p].x<<" "<<pts[p].y<<endl;
									}
								}
							}
						}
					
					}
				}
			}
		//	cout<<count<<endl;
			double val=(double)count/total;
			std::cout.setf( std::ios::fixed, std:: ios::floatfield ); 
			std::cout.precision(7);
			cout<<val<<endl;
			
	}
}
