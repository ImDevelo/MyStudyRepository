/* < C programing >                           Day 2019. 05. 11
 Project Title: Assignment 8. (10-5)
 Contents:����Լ��� ���� n factorial �Լ��� ������      */
#include<stdio.h>
//n factorial �Լ�
void factorial(int n, int *p) {
	if (n == 1)
		return;
	else{
		*p *= n;
		factorial(n - 1, p);	
	}
}

int main() {
	int result = 1;
	int n;
	int *ptr;
	ptr = &result;

	scanf("%d", &n);
	factorial(n, ptr);
	printf("%d factorial is %d", n, result);
}