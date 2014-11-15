#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
int main()
{
    vector <int> input;
    char str[100005];
    scanf("%s",str);
    int i=0;
    while(str[i+1]!='\0')
        input.push_back(str[i]-48);
    return 0;
}
