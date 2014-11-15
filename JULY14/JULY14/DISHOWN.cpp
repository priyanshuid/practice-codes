#include <iostream>
#include <stdio.h>
#include <math.h>
int bestDish[10005];
int parent[10005];
int findParent(int dish)
{
    while(dish!=parent[dish]){
        parent[dish]=parent[parent[dish]];
        dish=parent[dish];
    }
    return dish;
}
void clash(int firstDish, int secondDish){
    int firstChef=findParent(firstDish);
    int secondChef=findParent(secondDish);
    if(firstChef==secondChef){
        std::cout<<"Invalid query!"<<std::endl;
        return;
    }
    if(bestDish[firstChef]>bestDish[secondChef]){
        parent[secondChef]=firstChef;
    }else if(bestDish[secondChef]>bestDish[firstChef]){
        parent[firstChef]=secondChef;
    }
}
int main(){
    int totalCases;
    scanf("%d",&totalCases);
    for(int index=0;index<totalCases;index++){
        for(int localIndex=1;localIndex<10005;localIndex++){
            parent[localIndex]=localIndex;
        }
        int totalDishes;
        scanf("%d",&totalDishes);
        int dishes[totalDishes+1];
        for(int localIndex=1;localIndex<=totalDishes;localIndex++){
            scanf("%d",&dishes[localIndex]);
            bestDish[localIndex]=dishes[localIndex];
        }
        int numberOfQueries;
        scanf("%d",&numberOfQueries);
        for(int localIndex=0;localIndex<numberOfQueries;localIndex++){
            int type;
            scanf("%d",&type);
            if(type==0){
                int firstDish,secondDish;
                scanf("%d %d",&firstDish,&secondDish);
                clash(firstDish,secondDish);
            }else{
                int dishNumber;
                scanf("%d",&dishNumber);
                std::cout<<findParent(dishNumber)<<std::endl;
            }
        }
    }
    return 0;
}
