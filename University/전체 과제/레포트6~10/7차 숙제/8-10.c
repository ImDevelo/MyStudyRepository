/* < C programing >                           Day 2019. 05. 02
 Project Title: Assignment 7. (8-10)
 Contents: a�� b������ ����ϴ� ���α׷�                    */
#include<stdio.h>
 //a�� b������ ����ϴ��Լ�
int power(int a, int b) {
	if (b == 0)
		return 1;
	else
		return(a*power(a, b - 1));
}
int main() {
	int num1, num2;
	printf("Enter base and multiplier.\n");
	scanf("%d %d", &num1, &num2);
	printf("%d to the power of %d is %d.\n",num1, num2, power(num1,num2));
}

