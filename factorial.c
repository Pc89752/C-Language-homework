#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n;
	
	while(1){
		printf("Enter a nonnegative number : ");
		scanf(" %d",&n);
		
		if(n < 0){
			puts("Please enter again");
			continue;
		}else if(n == 0){
			puts("0! = 1");
			system("pause");
			exit(0);
		}else
			break;
	}
	
	int temp = n;
	unsigned int rslt = 1;
	
	for(;temp>0;temp--){
		rslt = rslt * temp;
	}
	
	printf("%d! = %d",n,rslt);

	system("pause");
} 
