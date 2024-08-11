/* < C programing >                                   Day 2019. 04. 04
 Project Title: Assignment 4. 5-14
 Contents:
 ���� ���α׷��� �����Ͽ� ���α׷��� �����ϸ� �ε� �Ҽ� �������� ����
 �������� ��� �Ŀ� ����� ����ϴ� ���α׷��� �ۼ��϶�.           */
#include <stdio.h>
int int_calculate(int, char, int);
float float_calculate(float, char, float);

int main() {
	int Mode_Select;
	double Number_1, Number_2;
	char Operator;

	printf("Enther 1 for floating point calculation, 2 for integer calculation\n");
	scanf("%d", &Mode_Select); //��� ����
	printf("Enter an expression. (for EXAMPLE, 2 + 5)\n");
	scanf("%lf %c %lf", &Number_1, &Operator, &Number_2); //����� �Է�

	//���� ���� ����, �ε��Ҽ� ���� ���� �� ����
	if (Mode_Select == 1) 
		float_calculate((float)Number_1, Operator, (float)Number_2);
	else if (Mode_Select == 2) 
	    int_calculate((int)Number_1, Operator, (int)Number_2);
	else
		printf("Error! Choose  Calculation Mode between '1' and '2'.\n");
	return 0;
}

// ���� ���� ����
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

// �ε� �Ҽ� ���� ����
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