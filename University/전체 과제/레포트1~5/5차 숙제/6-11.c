/* < C programing >                              Day 2019. 04. 11
 Project Title: Assignment 5. (6-11)
 Contents:
 '���� ��'�� 1�̿ܿ��� ������� ���� ���¸� ���Ѵ�. ������ a,b��
 ���ڷ� ���޵� �� ���� �Ҷ�� ����'y'�� �׷��� ������'n'�� ������
 �� �Լ��� �ۼ��ϰ� main���� �װ��� �ҷ� ����� ����ϴ� ���α׷�
 �� �ۼ��϶�,                                                  */
#include<stdio.h>
char mutally_prime(int a, int b);
int main() {
	int a, b;
	printf("Enter two numbers.\n");
	scanf("%d %d", &a, &b);
	if (mutally_prime(a, b) == 'y')
		printf("They are mutually prime.");
	if (mutally_prime(a, b) == 'n')
		printf("They are 'Not' mutually prime.");
}

//�� ���� ���μ����� �Ǻ��ϴ� �Լ�
char mutally_prime(int a, int b) { 
	int Lower_num, i;

	if (a < b) {
		Lower_num = a;
	}
	else if (a > b) {
		Lower_num = b;
	}

	for (i = 2; i <= Lower_num; i++) {
		if (a % i == 0&& b % i == 0)
			return 'n';
		else
			continue;
	}
	return 'y'; 
}
