/* < C programing >                                 Day 2019. 03. 28
 Project Title: Assignment 3. 4-2
 Contents: 
 ��p(x1,y1)�� ��(x2,y2)�� ��ǥ�� �Է¹޾� �� �� ���� �Ÿ��� ����ϴ� 
 ���α׷��� �ۼ��϶�. ��,x1,y1,x2,y2�� double�� �����Ѵ�.         */
#include <stdio.h>
#include<math.h>
double C_M(double s, double h);
double C_X2(double a, double b, double c, double d);

// �μ��� �� �� ��� �Լ�
double C_M(double s, double h) {
	return s - h;
}
// ������ �տ� ������ ��� �Լ�
double C_X2(double a, double b, double c, double d) {
	double distance;
	distance = sqrt((pow(C_M(a,c),2.0)) + (pow(C_M(b,d),2.0))); // ��Ʈ(����(�μ�����)+����(�μ�����))
	return distance;

}
//
int main() {
	double x1, y1, x2, y2;

	printf("Enter the coordinates of point p.\n");
	scanf("%lf %lf", &x1, &y1);
	printf("Enter the coordinates of point q.\n");
	scanf("%lf %lf", &x2, &y2);

	printf("Distance between the points is %lf", C_X2(x1, y1, x2, y2));

	return 0;

}