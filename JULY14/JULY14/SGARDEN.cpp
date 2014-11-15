#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <vector>
#define MODULAR 1000000007
bool visited[100005];
long long depthFirstSearch(int index, int connection[], long long count){
    if(index==connection[index]){
        visited[index]=true;
        count++;
        return count;
    }
    if(visited[index]!=true){
        visited[index]=true;
        count++;
        depthFirstSearch(connection[index], connection, count);
    }
    else{
        return count;
    }
}
long long gcdOfTwoNumbers(long long first, long long second){
    if(second==0){
        return first;
    }else{
        gcdOfTwoNumbers(second, first%second);
    }
}
long long modularInverse(long long a)  // from http://rosettacode.org/wiki/Modular_inverse#C.2B.2B
{
	long long b=MODULAR;
	long long b0=b,t,q;
	long long x0=0,x1=1;
	if (b==1) return 1;
	while(a>1){
		q=a/b;
		t=b, b=a%b, a=t;
		t=x0, x0=x1-q*x0, x1=t;
	}
	if (x1<0)x1+=b0;
	return x1;
}
long long findLeastCommonMultipleOfAList(std::vector<long long> countOfNodes){
   /* int index=countOfNodes.size()-1;
    long long modInverseOfLocalGCD;
    long long localLCM;
    while(countOfNodes.size()!=1){
        long long localGCD =gcdOfTwoNumbers(countOfNodes[index],countOfNodes[index-1]);
        if(localGCD==1){
            localLCM =(countOfNodes[index]*countOfNodes[index-1])%MODULAR;
        }else{
        modInverseOfLocalGCD=modularInverse(localGCD);
        localLCM =((countOfNodes[index]*countOfNodes[index-1])%MODULAR * (modInverseOfLocalGCD%MODULAR))%MODULAR;
        }
        countOfNodes.erase(countOfNodes.begin()+index);
        countOfNodes.erase(countOfNodes.begin()+index-1);
        countOfNodes.push_back(localLCM);
        index--;
    }*/
    long long finalLCM=1;
    int index=0;
    while(index<countOfNodes.size()){
        if(countOfNodes[index]!=1){
            for(int localIndex=index+1;localIndex<countOfNodes.size();localIndex++){
                countOfNodes[localIndex]/=gcdOfTwoNumbers(countOfNodes[index],countOfNodes[localIndex]);
            }
            finalLCM=(finalLCM*countOfNodes[index])%MODULAR;
        }
        index++;
    }
    return finalLCM;
}
int main(){
    int totalCases=0;
    std::cin>>totalCases;
    for(int index=0;index<totalCases;index++){
        for(int localIndex=0;localIndex<100005;localIndex++)
            visited[localIndex]=false;
        int totalNumbers=0;
        std::cin>>totalNumbers;
        int connection[totalNumbers+1];
        for(int localIndex=1;localIndex<=totalNumbers;localIndex++)
            scanf("%d",&connection[localIndex]);
        std::vector<long long> countOfNodes;
        for(int localIndex=1;localIndex<=totalNumbers;localIndex++){
            if(visited[localIndex]!=true){
                long long localValue=depthFirstSearch(localIndex, connection, 0L);
                if(localValue!=1 && localValue!=0)
                    countOfNodes.push_back(localValue);
            }
        }
        if(countOfNodes.size()==0){
            std::cout<<1<<std::endl;
            continue;
        }
        if(countOfNodes.size()==1){
            std::cout<<countOfNodes[0]<<std::endl;
            continue;
        }
        long long solution=findLeastCommonMultipleOfAList(countOfNodes);
        std::cout<<solution<<std::endl;
    }
    return 0;
}

