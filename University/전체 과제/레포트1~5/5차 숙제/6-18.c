/* < C programing >                            Day 2019. 04. 11
 Project Title: Assignment 5. (6-18)
 Contents:
 Ű�� ���ڿ��� �Է¹޾� ���ڿ��� '���� ������'������� ��ȣȭ��
 �� ���α׷��� �ۼ��϶�.                                        */
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