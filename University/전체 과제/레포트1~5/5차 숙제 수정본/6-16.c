/* < C programing >                            Day 2019. 04. 11
 Project Title: Assignment 5. (6-16)
 Contents:
 atoi�Լ��� ���� ¥�� ���α׷��� �ۼ��϶�. ���ڸ� ���� ��������
 �� ���� �� �װ��� ������ ��ȯ�Ͽ� ����ϴ� ���̴�. ������ ä��
 �� ���α׷��� �ϼ��غ���.                                    */
#include<stdio.h>	

int main() {
	char ch; int sum = 0;
	int value;

	printf("Enter a natual number.\n");
	while (1){
		scanf("%c", &ch);
		if (ch == '\n')
			break;
		value = ch - 48;
		sum = sum * 10 + value;
	}
	printf("You entered %d in decimal.\n", sum);
	return 0;
}