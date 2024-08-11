/* < C programing >                           Day 2019. 05. 18
 Project Title: Assignment 9. (10-8)
 Contents: 다항식 n차식을 호르너법칙을 이용하여 계산하는 프로그
 램을 완성하시오.                                            */
#include<stdio.h>
//호르너 계산 함수
double horner(const int n, const double p[], const double x) {
	int i;
	double sum = p[0];
	for (i = 1; i <= n; i++) {
		sum = sum * x + p[i];
	}
	return sum;
}

int main() {
	int Type_X, i;
	double value;
	double p[100];

	printf("Enter order of polynomial.\n");//차수 입력
	scanf("%d", &Type_X);
	printf("Enter %d coefficients.\n", Type_X + 1);//계수 입력
	for (i = 0; i < Type_X + 1; i++)
		scanf("%lf", &p[i]);
	printf("Enter the value of x.\n");//x값 입력
	scanf("%lf", &value);
	printf("The value of the polynomaial is %lf.", horner(Type_X, p, value));
	return 0;
}