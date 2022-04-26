/* < C programing >                           Day 2019. 05. 02
 Project Title: Assignment 7. (8-6)
 Contents: ������ �Ǵ� �������� ����� ���ϴ� ���α׷��� �����
 �� ��, ���� ���� �Լ��� �����϶�                            */

#include<stdio.h>
#include<stdarg.h>

// 2,3�� ���� ��ձ��ϴ� ���������Լ�
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

	if (count == 3) { // 3���� �Է�
		printf("Enter three integers.\n");
		scanf("%d %d %d", &n1, &n2, &n3);
		printf("Average value is %lf.\n", average(count, n1, n2, n3));
	}
	else if (count == 2) { // 2���� �Է�
		printf("Enter three integers.\n");
		scanf("%d %d", &n1, &n2);
		printf("Average value is %lf.\n", average(count, n1, n2));
	}
	else {
		printf("%d is not correct number.\n", count);
	}
	return 0;
}