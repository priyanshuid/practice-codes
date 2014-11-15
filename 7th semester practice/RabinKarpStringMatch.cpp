#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#define universe 256
#define MOD 269
using namespace std;
struct node{
	string str;
	node *next;
};
struct hashNode{
	int key;
	node *list;
};
hashNode hashTable[269];
int initialHashValue(string x, int length){
	int sum=0;
	for(int i=0;i<length;i++){
		char ch=x.at(i);
		sum+=(ch*(universe^(length-i)))%MOD;
	}
	return sum;
}
void preprocessTextToGetHashTable(string text, int n, int pat_length){
	int h0= initialHashValue(text, pat_length);
	string st0=text.substr(0, pat_length);
	node *list=new node();
	list->str = st0;
	list->next=NULL;
	hashTable[h0].list=list;
	int previousHash=h0;
	int powValue=1;
	for(int i=0;i<pat_length;i++)
		powValue= (powValue*universe)%MOD;
	for(int i=1;i<n-pat_length;i++)
	{
		int curHash= ((previousHash-(int)text.at(i-1)*powValue)*universe + text.at(i+pat_length))% MOD;
		string curString = text.substr(i, pat_length);
 		if((hashTable[curHash].list) == NULL)
		{
			node list;
			list.str = curString;
			list.next= NULL;
		}else{
			node *n = new node();
			n->str=curString;
			n->next = hashTable[curHash].list;
			hashTable[curHash].list= n;
		}
		previousHash=curHash;
	}
}

bool isPresentInText(string pat){
	int h0 = initialHashValue(pat, pat.length());
	bool ans = false;
	if(hashTable[h0].list == NULL)
		return false;
	else {
		node *LTBC = hashTable[h0].list;
		while(LTBC != NULL){
			if(LTBC->str.compare(pat))
				return true;
			LTBC = LTBC->next;
		}
	}
	return false;
}
int main(){
	string text, pat;
	cin>>text>>pat;
	for(int i=0;i<269;i++){
		hashTable[i].key= 0;
		hashTable[i].list=NULL;
	}
	preprocessTextToGetHashTable(text, text.length(), pat.length());
	bool result=isPresentInText(pat);
	cout<< ((result==true)? "PRESENT" : "NOT PRESENT")<<endl;
	return 0;
}
