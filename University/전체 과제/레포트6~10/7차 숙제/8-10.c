/* < C programing >                           Day 2019. 05. 02
 Project Title: Assignment 7. (8-10)
 Contents: a의 b제곱을 출력하는 프로그램                    */
#include<stdio.h>
 //a의 b제곱을 출력하는함수
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

