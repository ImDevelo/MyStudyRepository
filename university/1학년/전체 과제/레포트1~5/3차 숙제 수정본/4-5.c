/* < C programing >                                 Day 2019. 03. 28
 Project Title: Assignment 3. 4-5
 Contents:
 통계학에서 변이란 평균과의 차이 제곱을 모두 더해 그것을 데이터 수로
 나눈 값이다. 변이에 루트를 취하면 표준편차가 된다. 세개의 실수를 입
 력받은 후 표준편차를 계산하는 프로그램을 작성하되 main에서 반드시 p
 rintf("Standard devition is %lf.\n", std_devition(a,b,c));라는 명령
 문을 호출하라                                                    */
#include <stdio.h>
#include <math.h>
double average(double a, double b, double c);
double std_devition(double a, double b, double c);

// 세 수의 평균값 계산
double average(double a, double b, double c) {
	double total;
	total = (a + b + c) / 3;
	return total;
}

// 세 수의 표준 편차 값 계산
double std_devition(double a, double b, double c) {
	double total;
	total = sqrt((pow(average(a, b, c) - a,2.0) + pow(average(a, b, c) - b,2.0) + pow(average(a, b, c) - c,2.0)) / 3);
	return total;
}

int main() {
	double a, b, c;

	printf("Enter a three real number.\n");
	scanf("%lf %lf %lf", &a, &b, &c);
	printf("The standard devition is %lf.\n", std_devition(a, b, c));

	return 0;

}