#include <stdio.h>
#include <stdlib.h>

int main(void){
    float weight,height;
	
	printf("What's your weight ? (kilogram): ");
	scanf(" %f",&weight);
	
	printf("What's your height (meter):");
	scanf(" %f",&height);
	
	
	float BMI = weight / (height*height);
	printf("Your BMI : %.2f\n",BMI);

    if (BMI < 18.5)
    {
        printf("You're too thin.");
    }else if (BMI < 24)
    {
        printf("You're standard.");
    }else
    {
        printf("You're too fat.");
    }
}