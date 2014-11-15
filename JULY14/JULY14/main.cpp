#include <iostream>
#include <stdio.h>
#include <math.h>
int doi(){
    int totalCases=0;
    std::cin>>totalCases;
    for(int index=0;index<totalCases;index++){
        int sizeOfInput;
        std::cin>>sizeOfInput;
        int numberOfOnes=0;
        for(int localIndex=0;localIndex<sizeOfInput;localIndex++){
            char localCharacter;
            std::cin>>localCharacter;
            if(localCharacter=='1')
                numberOfOnes++;
        }
        long totalSubstrings=0;
        if(numberOfOnes<2){
            printf("%d\n",numberOfOnes);
            continue;
        }
        totalSubstrings=numberOfOnes*(numberOfOnes-1);
        totalSubstrings/=2;
        totalSubstrings+=numberOfOnes;
        printf("%ld\n",totalSubstrings);
    }
    return 0;
}
