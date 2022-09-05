/* < C programing >                                 Day 2019. 03. 28
 Project Title: Assignment 3. 4-2
 Contents: 
 점p(x1,y1)와 점(x2,y2)의 좌표를 입력받아 두 점 사이 거리를 출력하는 
 프로그램을 작성하라. 단,x1,y1,x2,y2는 double로 선언한다.         */
#include <stdio.h>
#include<math.h>
double C_M(double s, double h);
double C_X2(double a, double b, double c, double d);

// 두수의 차 값 계산 함수
double C_M(double s, double h) {
	return s - h;
}
// 제곱의 합에 제곱근 계산 함수
double C_X2(double a, double b, double c, double d) {
	double distance;
	distance = sqrt((pow(C_M(a,c),2.0)) + (pow(C_M(b,d),2.0))); // 루트(제곱(두수의차)+제곱(두수의차))
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