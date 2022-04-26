/* < C programing >                                 Day 2019. 04. 04
 Project Title: Assignment 4. 5-10
 Contents:
 세 개의 문자로 이루어진 단어를 입력받아 그 중 숫자를 나타내는 문자는
 몇개인지 출력하는 프로그램을 작성하라.                            */
#include<stdio.h>
char is_digit(int ch);
int Numder_Record(int, int, int);

int main() {
	char a, b, c;
	printf("Enter a 3-letter word.\n");
	scanf("%c%c%c", &a, &b, &c);
	printf("Digit appear %d times", Numder_Record(a, b, c));
}

char is_digit(int ch) {
	if (ch >= 48 && ch <= 57)
		return 1;
	else
		return 0;
}

int Numder_Record(int a, int b, int c) {
	int total;
	total = is_digit(a) + is_digit(b) + is_digit(c);
	return total;
}