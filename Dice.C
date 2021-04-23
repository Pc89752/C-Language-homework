#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	srand(time(NULL));
	int freq[13] ={0};
	
	float Expected[13] ={0};
	for(int i=1;i<=6;i++)
		for(int j=1;j<=6;j++)
			Expected[i+j] += 1.0/ 36;
	
	for(int i=0;i<36000;i++)
		freq[rand()%6+1 +rand()%6+1]++;
		
	printf("%4s%8s%16s%16s\n","sum" ,"Total" ,"Expected" ,"Actual");
	for(int i=2;i<=12;i++)
		printf("%4d%8d%16.3f%%%16.3f%%\n",
			 i, freq[i], Expected[i]* 100, freq[i]/ 36000.0*100);
} 
