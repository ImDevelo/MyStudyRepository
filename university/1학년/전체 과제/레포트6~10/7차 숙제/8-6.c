/* < C programing >                           Day 2019. 05. 02
 Project Title: Assignment 7. (8-6)
 Contents: 두정수 또는 세정수의 평균을 구하는 프로그램을 만들어
 라 단, 가변 길이 함수를 구현하라                            */

#include<stdio.h>
#include<stdarg.h>

// 2,3의 정수 평균구하는 가변길이함수
double average(int count, ...) {
	double average_sum, n1, n2, n3;
	va_list(p);
	va_start(p, count);
	n1 = va_arg(p, int);
	n2 = va_arg(p, int);
	n3 = va_arg(p, int);
	va_end(p);
	return ((n1 + n2 + n3) / (double)count);
}

int main() {
	int count;
	int n1, n2, n3;

	printf("Enter number of argument. It must be 2 or 3.\n");
	scanf("%d", &count);

	if (count == 3) { // 3정수 입력
		printf("Enter three integers.\n");
		scanf("%d %d %d", &n1, &n2, &n3);
		printf("Average value is %lf.\n", average(count, n1, n2, n3));
	}
	else if (count == 2) { // 2정수 입력
		printf("Enter three integers.\n");
		scanf("%d %d", &n1, &n2);
		printf("Average value is %lf.\n", average(count, n1, n2));
	}
	else {
		printf("%d is not correct number.\n", count);
	}
	return 0;
}