/* < C programing >                            Day 2019. 04. 11
 Project Title: Assignment 5. (6-18)
 Contents:
 키와 문자열을 입력받아 문자열을 '씨저 사이퍼'방법으로 암호화하
 는 프로그램을 작성하라.                                        */
#include<stdio.h>
int main() {
	int Key, num ,ch;

	printf("Enter the key.\n");
	scanf("%d", &Key);
	getchar();

	printf("Enter the text.\n");
	for (ch = getchar(); ch != '\n'; ch = getchar()) {
		num = ch + Key;
		num %= 128;
		putchar(num);
	}
	return 0;
}