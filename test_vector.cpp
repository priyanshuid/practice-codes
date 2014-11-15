#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <cctype>
#define push_back pb
using namespace std;
struct name
{
	struct name *next;
	int val;
};
int main()
{
	vector<name> names(10);
	vector<char> value(10);
	vector<char>::iterator p;
	p=value.begin();
	int i=0;
	while(p!=value.end())
	{
		*p=i+'a';
		p++;
		i++;
	
	}
	p=value.begin();
	while(p!=value.end())
	{
	
		cout<<*p<<" ";
		p++;
	}
	return 0;
	
}
