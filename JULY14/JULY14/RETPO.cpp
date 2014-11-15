#include <iostream>
#include <stdio.h>
#include <math.h>
int main(){
    int totalCases=0;
    std::cin>>totalCases;
    for(int index=0;index<totalCases;index++){
        int xCordinate,yCordinate;
        scanf("%d %d",&xCordinate,&yCordinate);
        xCordinate=(int)fabs((double)xCordinate);
        yCordinate=(int)fabs((double)yCordinate);
        long solution=0L;
        if(xCordinate>yCordinate){
            if((xCordinate+yCordinate)%2==0)
                solution=2*std::max(xCordinate,yCordinate);
            else solution=2*std::max(xCordinate,yCordinate)+1;
        }
        else{
            if((xCordinate+yCordinate)%2==0)
                solution=2*std::max(xCordinate,yCordinate);
            else solution=2*std::max(xCordinate,yCordinate)-1;
        }
        printf("%ld\n",solution);
    }
    return 0;
}
