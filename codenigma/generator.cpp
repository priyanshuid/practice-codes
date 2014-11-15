#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>
using namespace std;
int main()
{
        ofstream out("airplane_input.txt");

            int n,m;
            out<<1000<< " "<<9995<<endl;
             int i=0;
             while(i<9995)
             {
               int a=random()%1000;
                int b=random()%1000;
             if(a>0 && b>0 && a!=b)
             {
                out<<a<<" ";
                i++;
            }
             }
             return 0;
}
