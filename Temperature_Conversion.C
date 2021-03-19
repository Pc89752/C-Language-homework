#include <stdio.h>
#include <stdlib.h> 
#include <math.h>  

int main(void){
   	double Fahrenheit;
   	
	// output table column heads
	printf("%8s%21s\n", "Celsius", "Fahrenheit");
	
	for (int Celsius = 30 ; Celsius <= 50; Celsius++) {
	
	  // calculate new amount for specified year
		Fahrenheit = (9.0/5)* Celsius +32;
	
	  // output one table row
	  printf("%8d%21.10lf\n", Celsius, Fahrenheit);   
	}
} 
