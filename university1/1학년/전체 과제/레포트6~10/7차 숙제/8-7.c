/* < C programing >                           Day 2019. 05. 02
 Project Title: Assignment 7. (8-7)
 Contents: 1 ���� n���� ���ڸ� ���������� ����ϴ� ���α׷� */
#include<stdio.h>
// 1 ���� n���� ���ڸ� ���������� ����ϴ� �Լ�
void print_up(int n) {
	if (n == 0)
		return;
	else {
		print_up(n - 1);
		printf("%d ", n);
	}
}

int main() {
	int num;
	printf("Enter the last integer.\n");
	scanf("%d", &num);
	print_up(num);
}
