/* < C programing >                                 Day 2019. 04. 04
 Project Title: Assignment 4. 5-10
 Contents:
 �� ���� ���ڷ� �̷���� �ܾ �Է¹޾� �� �� ���ڸ� ��Ÿ���� ���ڴ�
 ����� ����ϴ� ���α׷��� �ۼ��϶�.                            */
#include<stdio.h>
char is_digit(int ch);
int Numder_Record(int, int, int);

int main() {
	char a, b, c;
	printf("Enter a 3-letter word.\n");
	scanf("%c%c%c", &a, &b, &c);
	printf("Digit appear %d times", Numder_Record(a, b, c));
}
// ���� �Ǻ� �Լ�
char is_digit(int ch) {
	if (ch > 64)
		return 0;
	else
		return 1;
}
// ���� ���� ��� �Լ�
int Numder_Record(int a, int b, int c) {
	int total;
	total = is_digit(a) + is_digit(b) + is_digit(c);
	return total;
}