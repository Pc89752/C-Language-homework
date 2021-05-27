#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265358979323846

double termOfSin(double radian);
double termOfCos(double radian);
void taylorSeries(double radian, double epsilon, double builtIn, double (*termOfTriFunc)(double));

int main(void){
	//宣告: 容錯量、弧度 
	double epsilon, theta, radian;
	
	//輸入誤差容錯量 
	printf("計算三角函數泰勒展開式用，請輸入誤差容錯量 : ");
	scanf(" %lf", &epsilon);
	
	//輸入計算用的角度
	printf("請輸入計算用的角度 : ");
	scanf(" %lf", &theta);
	
	//角度轉弧度 
	radian = theta* (M_PI/ 180);
	
	//選擇要計算的函數
	int choose;
	do {
		printf("請選擇要計算的函數 (1)SIN (2)COS : ");
		scanf(" %d", &choose);
	} while(choose != 1 && choose != 2);
	
	//根據選擇的函數去計算 
	switch(choose) {
		//計算 Sin
		case 1:
			taylorSeries(radian, epsilon, sin(radian), termOfSin);
			printf("內建函數計算結果 : %lf", sin(radian));
			break;
			
		//計算 Cos
		case 2:
			taylorSeries(radian, epsilon, cos(radian), termOfCos);
			printf("內建函數計算結果 : %lf", cos(radian));
			break;
			
		//出現重大錯誤 
		default:
			printf("ERROR!");
			exit(-1);
	}
}

double termOfSin(double radian){
	return radian;
}

double termOfCos(double radian){
	return 1;
}

void taylorSeries(double radian, double epsilon, double builtIn, double (*termOfTriFunc)(double)){
	double result=0, term, sign=-1;
	int i;
	
	//判斷要計算的函數來分配 i的值 
	term=(*termOfTriFunc)(radian);
	if(term == 1)
		i=0;
	else
		i=1;
	
	//泰勒展開 
	do {
		result += term;
		term *= sign* radian* radian/ ((i+1)*(i+2));
		i+=2;
	} while(fabs(builtIn-result) > epsilon);
	
	//i/2無條件退位後為展開的項數 
	i/=2;
	
	printf("泰勒展開式的項數 : %d\n", i);
	printf("泰勒展開式的結果 : %lf\n", result);
}


