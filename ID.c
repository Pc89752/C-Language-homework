#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int menu(int*);
int calculateID(char*);
void verifyID();
void IDGenerator(char*);
void fChrsGenerator(char*);

//英文字母作為首字元的值
const int fChrValues[26] = {
	10, 11, 12, 13, 14, 15, 16, 17, 34, 18,
	19, 20, 21, 22, 35, 23, 24, 25, 26, 27,
	28, 29, 32, 30, 31, 33
};

int main(void) {
	int choose;
	while (menu(&choose) == 1);
}

int menu(int* choose)
{
	printf("(1)身分證字號驗證 (2)身分證字號產生 (3)搜尋英文首字 (4)結束 -->請輸入選擇:");
	scanf(" %d", choose);
	for (int i = 1; i < 4; i++)
	{
		if (*choose == i) {
			switch (*choose)
			{
			case 1:
				verifyID();
				break;
			case 2:
				printf("");	//To prevent "E1072"
				char ID[11];
				ID[10] = '\0';
				IDGenerator(ID);
				printf("生成的身份證字號 : %s\n", ID);
				break;
			case 3:
				printf("");	//To prevent "E1072"
				char fChrs[10];
				fChrsGenerator(fChrs);
				printf("可做為首字元的字母 : %s\n", fChrs);
				break;
			default:
				break;
			}
			return 1;
		}
	}

	if (*choose == 4) {
		puts("結束");
		return 2;
	}

	puts("輸入錯誤!!!");
	return 1;
}

int calculateID(char* ID)
{
	int verifNum = 0;

	//計算首字元的2個值
	int value = fChrValues[ID[0] - 'A'];
	verifNum += value / 10;
	verifNum += (value % 10) * 9;

	//計算2~9位字元的值
	for (size_t i = 1; i < 9; i++)
	{
		verifNum += (ID[i] - '0') * (9 - i);
	}

	//計算最後一位字元的值
	verifNum += (ID[9] - '0');

	//回傳值
	return verifNum;
}

void verifyID()
{
	while (1)
	{
		//輸入
		char ID[20];
		ID[10] = '\0';
		printf("請輸入身份證字號:");
		scanf(" %s", &ID);

		//驗證長度
		if (strlen(ID) != 10) {
			puts("長度須為十位!!!");
				continue;
		}

		//驗證首字元
		if (!isupper(*ID)) {
			puts("首字元須為大寫英文字母!!!");
			continue;
		}

		//驗證後9個字元
		for (size_t i = 1; i < strlen(ID); i++)
		{
			if (!isdigit(ID[i])) {
				puts("後9個字元須為數字!!!");
				continue;
			}
		}

		//用特殊算法驗證
		if(calculateID(ID) %10 != 0) {
			puts("經算法驗證後不符!!!");
			continue;
		}

		puts("驗證通過");
		return;
	}
}

void IDGenerator(char* ID)
{
	srand(time(NULL));

	//生成首字元(出生登記縣市)
	int toContinue = 1;
	while (toContinue == 1)
	{
		toContinue = 0; 
		ID[0] = 'A' + rand() % 26;

		//已不再發配下述代碼
		char arr[] = { 'L','R','S','Y' };
		for (size_t i = 0; i < 4; i++)
		{
			if (ID[0] == arr[i]) {
				toContinue = 1;
				break;
			}
				
		}
	}

	//生成2~9位的字元
	for (size_t i = 1; i < 9; i++)
	{
		ID[i] = '0' + rand() % 10;
	}

	//計算前9位經運算後的值
	ID[9] = '0';	//預設第10位為0才能帶入函數運算
	int verifNum = calculateID(ID);
	ID[9] = '0' + 10 - verifNum % 10;
}

void fChrsGenerator(char* fChrs)
{
	//輸入身分證後9碼
	char IDNums[10];
	IDNums[9] = '\0';
	while (1)
	{
		int correct[2];

		printf("身分證後9碼 : ");
		scanf(" %s", IDNums);
		
		//是否有9碼
		if (strlen(IDNums) == 9)
		{
			correct[0] = 1;
		}
		else {
			correct[0] = 2;
		}

		//是否全是數字
		correct[1] = 1;
		for (size_t i = 0; i < 9; i++)
		{
			if (!isdigit(IDNums[i])) {
				correct[1] = 2;
				break;
			}
		}

		//報錯並重新輸入，或跳出迴圈
		if (correct[0] == 2)
		{
			puts("須輸入9碼");
		}
		else if (correct[1] == 2)
		{
			puts("9碼須全是數字");
		}
		else
		{
			break;	//輸入正確
		}
	}

	//建立身份證字號的字串
	char ID[11];
	ID[0] = 'A';	//在首端加上A方便函數計算
	ID[10] = '\0';

	//把輸入的數字輸入字串
	for (size_t i = 1; i < 10; i++)
	{
		ID[i] = IDNums[i-1];
	}

	//找出可以當首字元的英文大寫字母
	int verifNum = calculateID(ID) -1;	//-1是為了去除之前加上A的差值
	int fChrsLen = 0; //fChrs的長度
	for (size_t i = 0; i < 26; i++)
	{
		//以下代碼不確定需不需要加，因為可能要搜尋已經存在的身分證字號
		////如果為L, R, S, Y的話跳過(已不再賦配)
		//switch ('A'+ i)
		//{
		//	case 'L':
		//	case 'R':
		//	case 'S':
		//	case 'Y':
		//		continue;
		//}

		//算出從A數起，第i個字母作為首字元產生的值
		int value = 0;
		value = fChrValues[i] / 10;
		value += (fChrValues[i] % 10) * 9;

		//跟後9碼的值加起來是否被10整除，是的話則加入fChrs
		if ((value + verifNum) % 10 == 0) {
			fChrs[fChrsLen++] = 'A' + i;
		}

		value = 0; //將值歸零
	}

	fChrs[fChrsLen] = '\0';	//在最後加上結束字元
}
