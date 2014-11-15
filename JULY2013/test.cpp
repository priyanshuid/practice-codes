#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include <time.h>
using namespace std;
int main()
{
	
	ofstream op("op.txt");
	for(int i=0;i<100000;i++)
	op<<rand()%100<<" ";	
	return 0;
}
