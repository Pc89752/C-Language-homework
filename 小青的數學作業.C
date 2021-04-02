#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//分割括號 
void bracket(char *chStr_1[200], int *chStr_1Num_p, char *chStr, unsigned int start);
//子字串函式 
void subStr(char *dest, const char *src, unsigned int start, unsigned int cnt);

int main(void){
	//1. 輸入並辨識輸入的字元
	
	//1.1. 輸出提示字元
	puts("請輸入運算式：\t(輸入@結束)");
	
	//1.2. 輸入數學運算式
	//1.3. 將運算式分割成字元陣列
	char chStr[1500];
	for(int i=0;i<1500;i++){
		char ch = getch();
		
		chStr[i] = ch;
		if(ch == '@')
			break;
		printf("%c",ch);
	}
	
	puts("\n你輸入的數學運算式為:");
	for(int i=0;chStr[i]!='@';i++){
		printf("%c",chStr[i]);
	}
	
	//2. 分割出片段並分出先後順序
	
	//2.1. 分出以括號分隔的片段
	int chStr_1Num = 0;
	int *chStr_1Num_p =&chStr_1Num;
	char *chStr_1[200];
	for(unsigned int i=0;chStr[i]!='@';i++){
		if(chStr[i] == '(')
			bracket(chStr_1, chStr_1Num_p, chStr, i);
	} 
}

//分割括號 
void bracket(char *chStr_1[200], int *chStr_1Num_p, char *chStr, unsigned int start){
	for(int i=start;chStr[i]!='@';i++){
		if(chStr[i] == '(')
			bracket(chStr_1, chStr_1Num_p, chStr, i);
		if(chStr[i] == ')'){
			int cnt = i;
			subStr(chStr_1[*chStr_1Num_p], chStr, start, cnt);
			++*chStr_1Num_p;
		}	
	}
}

//子字串函式 
void subStr(char *dest, const char *src, unsigned int start, unsigned int cnt) {
   	strncpy(dest, src + start, cnt);
   	dest[cnt] =   0 ;
}