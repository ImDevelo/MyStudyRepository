/* < C programing >                                 Day 2019. 03. 28
 Project Title: Assignment 3. 4-5
 Contents:
 ����п��� ���̶� ��հ��� ���� ������ ��� ���� �װ��� ������ ����
 ���� ���̴�. ���̿� ��Ʈ�� ���ϸ� ǥ�������� �ȴ�. ������ �Ǽ��� ��
 �¹��� �� ǥ�������� ����ϴ� ���α׷��� �ۼ��ϵ� main���� �ݵ�� p
 rintf("Standard devition is %lf.\n", std_devition(a,b,c));��� ���
 ���� ȣ���϶�                                                    */
#include <stdio.h>
#include <math.h>
double average(double a, double b, double c);
double std_devition(double a, double b, double c);

// �� ���� ��հ� ���
double average(double a, double b, double c) {
	double total;
	total = (a + b + c) / 3;
	return total;
}

// �� ���� ǥ�� ���� �� ���
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