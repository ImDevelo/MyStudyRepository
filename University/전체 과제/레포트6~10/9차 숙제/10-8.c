/* < C programing >                           Day 2019. 05. 18
 Project Title: Assignment 9. (10-8)
 Contents: ���׽� n������ ȣ���ʹ�Ģ�� �̿��Ͽ� ����ϴ� ���α�
 ���� �ϼ��Ͻÿ�.                                            */
#include<stdio.h>
//ȣ���� ��� �Լ�
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

	printf("Enter order of polynomial.\n");//���� �Է�
	scanf("%d", &Type_X);
	printf("Enter %d coefficients.\n", Type_X + 1);//��� �Է�
	for (i = 0; i < Type_X + 1; i++)
		scanf("%lf", &p[i]);
	printf("Enter the value of x.\n");//x�� �Է�
	scanf("%lf", &value);
	printf("The value of the polynomaial is %lf.", horner(Type_X, p, value));
	return 0;
}