#include <stdio.h>
#include <stdlib.h>

int main(void){
	double e=1;
	unsigned int dnmntr = 1;
	for(int i=1;dnmntr<1000000000;i++){
		dnmntr = dnmntr * i;
		e = e + 1.0/dnmntr; 
	}
	
	printf("e = %lf\n",e);
	system("pause");
}
