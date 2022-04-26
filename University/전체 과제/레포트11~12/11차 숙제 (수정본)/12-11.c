/* < C programing >                           Day 2019. 06. 01
 Project Title: Assignment 11. (12-11)
 Contents: Hasy Key 함수를 통해 strstr을 만들어라           */
#include<stdio.h>
#include<string.h>

//Hasy Key값 계산
int Hasy_Key(char *str, int lg) {
	int sum = 0,i,tens=1;
	for (i = 0; i < lg; i++) {
		sum += (int)(str[i])*tens;
		tens *= 10;
	}
	return sum;
}

//찾고자하는 Hasy Key값과 문장 비교
char *strstr_by_hash(const char *str1, const char *str2) {
	int i,j;
	int leng = strlen(str2);//Hasy Key 길이
	int Key = Hasy_Key(str2, leng);//Hasy Key 값 비교
	int State = 0;
	
	for (i = 0; i < leng; i++) {
		if (Key == Hasy_Key(str1, leng)) {//Hsay Key가 맞다면
			State = 1;
			for (j = 0; j < leng; j++) {//문자 순서가 맞는지 비교
				if (str1[j] != str2[j])
					State = 0;
			}
			if (State = 1)
				return str1;
		}
		str1++;
	}
	return NULL;
}

int main() {
	char text[60], S_txt[10];
	char* ret;
	printf("Enter text.\n");
	gets(text);
	printf("Enter serch string.\n");
	gets(S_txt);

	ret = strstr_by_hash(text, S_txt);
	(ret == NULL) ? printf("No such string.\n") : puts(ret);

	return 0;
}