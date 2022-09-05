/*  < C programing >                             Day 2019. 03. 20
 Project Title:  Assignment 2. 2-7
 Contents:
  실수를 입력받은 후에 형 변환 연산자를 써서 입력받은 값을 정수형
 으로 출력하라                                                   */

#include <stdio.h>

int main() {

	double Numder;

	printf("Enter a real numder.\n");
	scanf("%lf", &Numder);
	printf("%d\n", (int)Numder);
	return 0;

}
