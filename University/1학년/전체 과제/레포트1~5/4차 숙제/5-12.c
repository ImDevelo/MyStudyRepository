/* < C programing >                                 Day 2019. 04. 04
 Project Title: Assignment 4. 5-12
 Contents:
 ���� ���ϴ� ����� �ϳ��� ü���� ����(BMI)�� �����Ը� Ű�� ����
 ���� ���� �����μ� �̱��� BMI������ 18.5 �̸��̸� ��ü������, 18.5
 �̻� 25.0�̸��̶�� ���� ü��, 25.0�̻��̸� ��ü������ �з��Ѵ�. ��
 ���Կ� Ű�� �Է¹޾� BMI �򰡰���� ����ϴ� ���α׷��� �ۼ��϶�. */
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

//BMI �򰡰���� ��� �Լ�
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