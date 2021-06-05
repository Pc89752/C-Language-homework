#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void repeatVowel(char*, const char*);
void pigLatin(const char* [4][5]);
void substr(char* dest, char* src, size_t start, size_t len);

int main(void)
{
	srand(time(NULL));

	//宣告字句片段
	char* words[4][5] = {
		{"the", "a", "one", "some", "any"},
		{"boy", "girl", "dog", "town", "car"},
		{"drove", "jumped", "ran", "walked", "skiped"},
		{"to", "from", "over", "under", "on"}
	};

	// 印20行
	for (size_t i = 0; i < 20; i++)
	{
		pigLatin(words);
	}
}

void repeatVowel(char* dest, const char* src)
{
	// 選定插入位置和插入字母
	size_t pos = strcspn(src, "aeiou");
	char c[2];
	substr(c, src, pos, 1);
	//printf("Insert %s\n", c);
	//printf("Insert after %d character\n", pos);

	char str[10];

	// 輸入前面的部分
	substr(dest, src, 0, pos);

	//在母音前插入母音
	strcat(dest, c);

	// 輸入後面的部分
	substr(str, src, pos, strlen(src) - pos);
	strcat(dest, str);
}

void pigLatin(const char* words[4][5])
{
	for (size_t i = 0;; i++)
	{
		char str[10];

		// words的 : 0 -> 1 -> 2 -> 3 -> 0 -> 1
		// 冠詞 -> 名詞 -> 動詞 -> 介詞 -> 冠詞 -> 名詞
		repeatVowel(str, words[i % 4][rand() % 5]);
		size_t len = strlen(str);

		//從第2個字元開始印
		for (size_t j = 1; j < len; j++)
		{
			printf("%c", str[j]);
		}

		//印第1個字元加ay
		printf("%cay", str[0]);

		// 在單字後加空格，或完成句子後換行
		if (i == 5) {
			puts(".");
			break;
		}
		else
		{
			printf(" ");
		}
	}
}

void substr(char* dest, char* src, size_t start, size_t len) {
	strncpy(dest, src + start, len);
	*(dest + len) = 0;
}