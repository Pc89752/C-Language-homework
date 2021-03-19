#include <stdio.h>
#include <stdlib.h> 
#include <math.h>  

int main(void){
   	double prncpl; 	// starting principal
   	double rate; 	// annual interest rate
   	int years;		// the year that stop counting
	
	//Enter the principal
	printf("How much is the principle ? : ");
	scanf(" %lf",&prncpl);
	
	//Enter the rate
	printf("What is the rate ? : ");
	scanf(" %lf",&rate);
	
	//Enter the years
	printf("How many years ? : ");
	scanf(" %d",&years);
	
	// output table column heads
	printf("%4s%21s\n", "Year", "Amount on deposit");
	
	double amount=prncpl;
	for (int crrntYr = 1 ; crrntYr <= years; crrntYr++) {
	
	  // calculate new amount for specified year
		amount *= (1 + rate);
	
	  // output one table row
	  printf("%4d%21.2lf\n", crrntYr, amount);   
	}
} 
