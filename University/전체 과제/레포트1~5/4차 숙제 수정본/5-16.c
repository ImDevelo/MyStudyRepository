/* < C programing >                                    Day 2019. 04. 04
 Project Title: Assignment 4. 5-16
 Contents:
 2�� �����Ŀ��� �Ǻ��� D�� ������ ��쿡�� ���Ҽ��� ó���� �� �ִ�. ����
 ���,sqrt(-9.0) = sqrt(9.0 * -1) = sqrt(9) * sqrt(-1) = 3.0 i �� ó����
 �� �ִ�. ���⼭ i�� �����ؼ� -1�� �Ǵ� ����� ������ imaginary number��
 �ǹ��Ѵ�. ���� 5-11�� �����Ͽ� D<0�� ���� ���� ����ϴ� ���α׷��� �ۼ�
 �϶�.                                                                */
#include<stdio.h>
#include<math.h>
//�Լ� ����___________________________________________________________//
void Zero_order(int, int, int);
void First_order(int, int, int);
void Second_order(int, int, int);
double Calc_D(int, int, int);
void Calc_Imaginary(int, int, int);
void  Calc_actual(int, int, int);
/////////////////////////////////////////////////////////////////////////

// Main �Լ�
int main() {
	int a, b, c;
	printf("Enter the coefficients a, b, c.\n");
	scanf("%d%d%d", &a, &b, &c);

	// ����, ����, ��� �Լ��Ǻ�
	if (a != 0)
		Second_order(a, b, c);
	else if (b != 0)
		First_order(a, b, c);
	else
		Zero_order(a, b, c);
	return 0;
	
}
	
// �Ǻ��� D �Լ�
double Calc_D(int a, int b, int c) {
	return (double)(b*b - 4 * a * c);
}

// ���� 2�� �϶� ���� ������̳� �Ǳ��̳� �Ǻ��ϴ� �Լ�
void Second_order(int a, int b, int c) {
	if (Calc_D(a, b, c) >= 0)
		Calc_actual(a, b, c);
	else
		Calc_Imaginary(a, b, c);
	return;
}

// �Ǽ�(����)�� ���
void  Calc_actual(int a, int b, int c) {
	double root1, root2, D, root_D;
	D = Calc_D(a, b, c);
	root_D = sqrt(D);
	root1 = (-b + root_D) / (double)(2 * a);
	root2 = (-b - root_D) / (double)(2 * a);
	printf("The root are %.3f, %.3f.\n", root1, root2);
}

// ��� �� ���
void Calc_Imaginary(int a, int b, int c) {
	double D, root_D, root_ac, root_im;
	D = -Calc_D(a, b, c);
	root_D = sqrt(D);
	root_ac = -b / (double)(2 * a);
	root_im = root_D / (double)(2 * a);
	printf("The root are %.3f+%.3fi, %.3f-%.3fi", root_ac, root_im, root_ac, root_im);
}

//1�� ������ �� ��� �Լ�
void First_order(int a, int b, int c) {
	printf("The root is, %.3f.\n", (-c) / (double)b);
}

//0�� ������ ��� �Լ�
void Zero_order(int a, int b, int c) {
		printf("there is no root.\n");
	}