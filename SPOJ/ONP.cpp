#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <stack>
#include <map>
#include <queue>
using namespace std;
string compute(string str){
    stack <char> stk;
    map<char, int> symbols;

    symbols['(']=0;
    symbols['+']=1;
    symbols['-']=2;
    symbols['*']=3;
    symbols['/']=4;
    symbols['^']=5;
    string output="";
    stk.push('(');
    str+=')';
    int i=0;
    while(!stk.empty() && i<str.length()){
        if(str.at(i)>='a' && str.at(i)<='z')    {output +=str.at(i); i++;continue;}
        if(str.at(i) == '('){ stk.push('('); i++;continue;}
        if(str.at(i) == ')'){
            while(stk.top()!='('){
                char a=stk.top();
                output+=a;
                stk.pop();
            }
            stk.pop();
        }

        else{

            while(symbols[stk.top()] > symbols[str.at(i)]){
                output +=stk.top();
                stk.pop();
            }stk.push(str.at(i));
        }
        i++;
    }
    return output;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        string ans = compute(str);
        cout<<ans<<endl;
    }

}
