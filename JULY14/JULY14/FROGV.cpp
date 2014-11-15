#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
struct frogIDMd{
    int index;
    long long distance;
    long long maxDistance;
};
bool comparePositionFromOrigin(const frogIDMd &frog1, const frogIDMd &frog2){
    return frog1.distance<=frog2.distance;
}
bool compareIndexOfFrogs(const frogIDMd &frog1, const frogIDMd &frog2){
    return frog1.index<frog2.index;
}
int main(){
    int totalFrogs=0;
    int rangeOfSending=0;
    int numberOfQueries=0;
    std::cin>>totalFrogs>>rangeOfSending>>numberOfQueries;
    frogIDMd frogs[totalFrogs];
    for(int localIndex=0;localIndex<totalFrogs;localIndex++){
        frogs[localIndex].index=localIndex;
        scanf("%lld",&frogs[localIndex].distance);
        frogs[localIndex].maxDistance=0;
    }
    std::sort(frogs,frogs+totalFrogs,comparePositionFromOrigin);
    frogs[totalFrogs-1].maxDistance=frogs[totalFrogs-1].distance+rangeOfSending;
    for(int index=totalFrogs-2;index>=0;index--){
        if(frogs[index].distance+rangeOfSending>=frogs[index+1].distance)
            frogs[index].maxDistance=frogs[index+1].maxDistance;
        else
            frogs[index].maxDistance=frogs[index].distance+rangeOfSending;
    }
    std::sort(frogs,frogs+totalFrogs,compareIndexOfFrogs);
    for(int index=0;index<numberOfQueries;index++){
        int fromIndex,toIndex;
        scanf("%d%d", &fromIndex, &toIndex);
        if(fromIndex==toIndex){
            std::cout<<"Yes"<<std::endl;
            continue;
        }
        if(frogs[fromIndex-1].distance > frogs[toIndex-1].distance)
        {
            int temp=fromIndex;
            fromIndex=toIndex;
            toIndex=temp;
        }
        if(frogs[fromIndex-1].maxDistance>=frogs[toIndex-1].distance)
            std::cout<<"Yes"<<std::endl;
        else
            std::cout<<"No"<<std::endl;
    }
    return 0;
}
