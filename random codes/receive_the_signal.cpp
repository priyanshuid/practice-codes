#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b){
    long long ans=1;
    for(int i=0;i< b;i++)
        ans=ans*a;
    return ans;
}
long long fact(long long a){
    long long ans=1;
    for(int i=1;i<=a;i++){
        ans= ans*i;
    }
    return ans;
}
int main(){
    string str1, str2;
    cin>>str1>>str2;
    int counter=0;
    for(int i=0;i< str1.length();i++){
        if(str1.at(i)=='+')counter++;
        else if(str1.at(i)=='-')counter--;
    }
    int counter2=0;
    int num_ques=0;
    for(int i=0;i<str2.length();i++){
        if(str2.at(i)=='+')counter2++;
        else if(str2.at(i)=='?')num_ques++;
        else if(str2.at(i)=='-')counter2--;
    }
    int val= counter2>counter ? counter2-counter : counter-counter2;
    if(val > num_ques) {
        printf("%.15lf\n",0.0);
        exit(0);

    }
    if((num_ques + val) %2 == 0 && (num_ques - val)%2==0){
        long long den = power((long long)2, num_ques);
        long long num = fact(num_ques)/ (fact((val+num_ques)/2 )*fact((num_ques-val)/2));
        printf("%.15lf\n",(double)num/den);
    }else printf("%.15lf\n",0.0);

}
