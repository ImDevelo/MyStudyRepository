/* < C programing >                           Day 2019. 06. 01
 Project Title: Assignment 11. (12-9)
 Contents: 한글이 몇글자인지 출력하는 프로그램을 만들어라   */
#include<stdio.h>
#include<string.h>

//한글문자 갯수 count
int k_letters(const char *string) {
	int count=0,i;
	for (i = 0; string[i] != '\0';) {
		if (string[i] >= 0 && string[i] <= 127)//아스키값은 pass
			i++;
		else{
			i += 2;
			count++;
		}
	}
	return count;
}

int main() {
	char str[100];
	while (1){
		printf("Enter a sentence with Korean and English letter.\n");
		gets(str);
		if (strcmp(str, "quit") == 0)
			break;
		printf("한글문자는 %d 나옵니다.\n", k_letters(str));
	}
	return 0;
}