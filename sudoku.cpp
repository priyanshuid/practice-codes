/*Author priyanshu singh*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <math.h>
#include <map>
#include <fstream>
#define unsigned long long ull
using namespace std;
bool FindUnassignedLoc(int ar[][9],int &row,int &col);
bool conflict(int ar[][9],int row,int col,int num);
bool checkInBox(int ar[][9],int row,int col,int num);
bool solve(int ar[][9])
{
	int row=0,col=0;
	if(!FindUnassignedLoc(ar,row,col))
		return true;
	for(int i=1;i<=9;i++)
	{
		if(!conflict(ar,row,col,i))
		{
			ar[row][col]=i;
			if(solve(ar))
			return true;
			ar[row][col]=0;
		}
	}
	return false;
}
bool FindUnassignedLoc(int ar[][9],int &row,int &col)
{
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(ar[i][j]==0)
			{
				row=i;col=j;
				return true;
			}
		}
	}
	return false;
}
bool conflict(int ar[][9],int row,int col,int num)
{
	for(int i=0;i<9;i++)
	{
		if(i!=row)
		{
			if(ar[i][col]==num)
				return true;
		}
	}
	for(int j=0;j<9;j++)
	{
		if(j!=col)
		{
			if(ar[row][j]==num)
				return true;
		}
	}
	if(checkInBox(ar,row,col,num))
		return true;
		
	return false;
}
bool checkInBox(int ar[][9],int row,int col,int num)
{
	int i=row,j=col;
	int cn,rn;
	if(i<3)
		cn=1;
		else if(i=3 && i<6)
			cn=2;
			else 
				cn=3;
	if(j<3)
		rn=1;
			else if(j>=3 && j<6)
				rn=2;
					else
						rn=3;
	for(int i1=(cn-1)*3;i1<cn*3;i1++)
	{
		for(int j1=(rn-1)*3;j1<rn*3;j1++)
		{
			if(i1!=i && j1!=j)
			{
				if(ar[i1][j1]==num)
				return true;
			}
		}			
	}
	return false;
}
int main()
{
//	ifstream inp("sudoku_inp.txt");
	int ar[9][9];
	cout<<"||||        Welcome To The Sudoku Solver       ||||\n";
	cout<<"Enter the problem and i'll solve it for you , master :)"<<endl;
	cout<<"Enter the initial entries"<<endl;
	cout<<"Input 0 to represent voids :)"<<endl;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cin>>ar[i][j];
		}
	}
//	inp.close();
	cout<<"Please Wait..........\n"<<endl;
	solve(ar);
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			cout<<ar[i][j]<<" ";
		cout<<endl;
	}
	cout<<"Thanks for using. \nAuthor Priyanshu Singh"<<endl;
	return 0;
}
