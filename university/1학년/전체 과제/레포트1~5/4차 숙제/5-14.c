/* < C programing >                                   Day 2019. 04. 04
 Project Title: Assignment 4. 5-14
 Contents:
 계산기 프로그램을 수정하여 프로그램이 시작하면 부동 소수 연산인지 정수
 연산인지 물어본 후에 결과를 출력하는 프로그램을 작성하라.           */
#include <stdio.h>
int int_calculate(int, char, int);
float float_calculate(float, char, float);

int main() {
	int Mode_Select;
	double Number_1, Number_2;
	char Operator;

	printf("Enther 1 for floating point calculation, 2 for integer calculation\n");
	scanf("%d", &Mode_Select); //모드 선택
	printf("Enter an expression. (for EXAMPLE, 2 + 5)\n");
	scanf("%lf %c %lf", &Number_1, &Operator, &Number_2); //연산식 입력

	//정수 연산 계산기, 부동소수 연산 계산기 중 선택
	if (Mode_Select == 1) 
		float_calculate((float)Number_1, Operator, (float)Number_2);
	else if (Mode_Select == 2) 
	    int_calculate((int)Number_1, Operator, (int)Number_2);
	else
		printf("Error! Choose  Calculation Mode between '1' and '2'.\n");
	return 0;
}

// 정수 연산 계산기
int int_calculate(int num1, char op, int num2) {
	switch (op) {
	case'+':
		printf("%d + %d = %d.\n", num1, num2, num1 + num2);
		break;
	case'-':
		printf("%d - %d = %d.\n", num1, num2, num1 - num2);
		break;
	case'*':
		printf("%d * %d = %d.\n", num1, num2, num1 * num2);
		break;
	case'/':
		printf("%d / %d = %d.\n", num1, num2, num1 / num2);
		break;
	case'%':
		printf("%d %% %d = %d.\n", num1, num2, num1 % num2);
		break;
	default:
		printf("Error! Not an allowable operator,\n");
		break;
	}
}

// 부동 소수 연산 계산기
float float_calculate(float num1, char op, float num2) {
	
	switch (op) {
	case'+':
		printf("%f + %f = %f.\n", num1, num2, num1 + num2);
		break;
	case'-':
		printf("%f - %f = %f.\n", num1, num2, num1 - num2);
		break;
	case'*':
		printf("%f * %f = %f.\n", num1, num2, num1 * num2);
		break;
	case'/':
		printf("%f / %f = %f.\n", num1, num2, num1 / num2);
		break;
	case'%':
		printf("%f %% %f = %d.000000.\n", num1, num2, (int)num1 % (int)num2);
		break;
	default:
		printf("Error! Not an allowable operator,\n");
		break;
	}
}