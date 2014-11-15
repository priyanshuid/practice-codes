#include <iostream>
#include <stdio.h>
#include <math.h>
int main(){
    int totalCases=0;
    std::cin>>totalCases;
    for(int index=0;index<totalCases;index++){
        int sizeOfInput;
        std::cin>>sizeOfInput;
        char array[100000];
        long long numberOfOnes=0;
        for(int localIndex=0;localIndex<sizeOfInput;localIndex++){
            char localCharacter;
            std::cin>>array[localIndex];
        }
        long long totalSubstrings=0L;
         for(int localIndex=0;localIndex<sizeOfInput;localIndex++){
             if(array[localIndex]=='1')
                numberOfOnes++;

         }
        totalSubstrings= ((numberOfOnes*(numberOfOnes-1))/2);
        totalSubstrings+=numberOfOnes;
        std::cout<<totalSubstrings<<std::endl;
    }
    return 0;
}
