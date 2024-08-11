/* < C programing >                                    Day 2019. 04. 04
 Project Title: Assignment 4. 5-16
 Contents:
 2차 방정식에서 판별식 D가 음수일 경우에는 복소수로 처리할 수 있다. 예를
 들어,sqrt(-9.0) = sqrt(9.0 * -1) = sqrt(9) * sqrt(-1) = 3.0 i 로 처리할
 수 있다. 여기서 i는 제곱해서 -1이 되는 수라는 점에서 imaginary number를
 의미한다. 예제 5-11을 수정하여 D<0일 때도 근을 출력하는 프로그램을 작성
 하라.                                                                */
#include<stdio.h>
#include<math.h>
//함수 정의___________________________________________________________//
void Zero_order(int, int, int);
void First_order(int, int, int);
void Second_order(int, int, int);
double Calc_D(int, int, int);
void Calc_Imaginary(int, int, int);
void  Calc_actual(int, int, int);
/////////////////////////////////////////////////////////////////////////

// Main 함수
int main() {
	int a, b, c;
	printf("Enter the coefficients a, b, c.\n");
	scanf("%d%d%d", &a, &b, &c);

	// 이차, 일차, 상수 함수판별
	if (a != 0)
		Second_order(a, b, c);
	else if (b != 0)
		First_order(a, b, c);
	else
		Zero_order(a, b, c);
	return 0;
	
}
	
// 판별식 D 함수
double Calc_D(int a, int b, int c) {
	return (double)(b*b - 4 * a * c);
}

// 근이 2개 일때 근이 허수값이냐 실근이냐 판별하는 함수
void Second_order(int a, int b, int c) {
	if (Calc_D(a, b, c) >= 0)
		Calc_actual(a, b, c);
	else
		Calc_Imaginary(a, b, c);
	return;
}

// 실수(정수)값 계산
void  Calc_actual(int a, int b, int c) {
	double root1, root2, D, root_D;
	D = Calc_D(a, b, c);
	root_D = sqrt(D);
	root1 = (-b + root_D) / (double)(2 * a);
	root2 = (-b - root_D) / (double)(2 * a);
	printf("The root are %.3f, %.3f.\n", root1, root2);
}

// 허수 값 계산
void Calc_Imaginary(int a, int b, int c) {
	double D, root_D, root_ac, root_im;
	D = -Calc_D(a, b, c);
	root_D = sqrt(D);
	root_ac = -b / (double)(2 * a);
	root_im = root_D / (double)(2 * a);
	printf("The root are %.3f+%.3fi, %.3f-%.3fi", root_ac, root_im, root_ac, root_im);
}

//1차 방정식 근 계산 함수
void First_order(int a, int b, int c) {
	printf("The root is, %.3f.\n", (-c) / (double)b);
}

//0차 방정식 출력 함수
void Zero_order(int a, int b, int c) {
		printf("there is no root.\n");
	}