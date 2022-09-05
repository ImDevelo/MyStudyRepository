/* < C programing >                          Day 2019. 06. 01
 Project Title: Assignment 11. (12-16)
 Contents: 한글 문장을 입력받아 그것이 회문인지 판단하는 프로
 그램을 작성하라.                                          */
#include<stdio.h>
#include<string.h>
//한글 회문 판별하는 프로그램
int k_palindrome(const char *string) {
	int i,j=0, first, last;
	char H_str[100];
	char ch1, ch2;

	for (i = 0; string[i] != '\0'; i++)//빈칸, 기호 제외하여 H_str에 한글만 저장
		if (!(string[i] >= 32 && string[i] <= 47)) {
			H_str[j++] = string[i++];
			H_str[j++] = string[i];
		}
	first = 0, last = j; j = 0;
	for (i = last-1; i >= first; ) {//한글만 남은상태에서 회문판단
		if ((H_str[i - 1] != H_str[j])|| (H_str[i] != H_str[j+1]))
			return 0;
		i -= 2; j += 2;
	}
	return 1;
}

int main() {
	while (1){
		char str[100];
		int lim;
		printf("한글 문장을 입력하시오.\n");
		gets(str);
		if (strcmp(str, "quit") == 0)
			break;

		lim = k_palindrome(str);
		(lim)? printf("네 회문입니다.\n"): printf("회문이 아닙니다.\n");
		return 0;
	}
}