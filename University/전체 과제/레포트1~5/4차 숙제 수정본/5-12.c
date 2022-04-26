/* < C programing >                                 Day 2019. 04. 04
 Project Title: Assignment 4. 5-12
 Contents:
 비만을 평가하는 방법중 하나인 체질량 지수(BMI)는 몸무게를 키의 제곱
 으로 나눈 값으로서 미국은 BMI지수가 18.5 미만이면 저체중으로, 18.5
 이상 25.0미만이라면 정상 체중, 25.0이상이면 과체중으로 분류한다. 몸
 무게와 키를 입력받아 BMI 평가결과를 출력하는 프로그램을 작성하라. */
#include <stdio.h>
#include <math.h>

double BMI_print(double, double);

int main() {
	double Blank1, Blank2;
	printf("Enter your weight\n");
	scanf("%lf", &Blank1);
	printf("Entee your height.\n");
	scanf("%lf", &Blank2);

	BMI_print(Blank1, Blank2);
	return 0;
}

//BMI 평가결과를 출력 함수
double BMI_print(double a, double b) {
	double BMI_point;
	BMI_point = a / (double)pow(b, 2.0);
	if (BMI_point < 18.5)
		printf("your BMI is %.2lf. It Underweight. \n", BMI_point);
	else if (BMI_point >= 18.5&&BMI_point < 25.0)
		printf("your BMI is %.2lf. It normal. \n", BMI_point);
	else if (BMI_point >= 25.0)
		printf("your BMI is %.2lf. It Overweight. \n", BMI_point);
	else
		printf("Error! \n");
	return;

}