/* < C programing >                                 Day 2019. 03. 27
 Project Title: Assignment 3. 3-2
 Contents:
 세개의 정수를 입력받아 평균을 구하는 프로그램을 작성하라. 단 출력은
 double형으로서 소수 이하 3자리까지 출력하기로 한다. 입력은 한줄로 이
 어지되 입력 사이는 빈칸으로 구분하기로 한다.                      */
#include <stdio.h>

int main() {
	int Blank1, Blank2, Blank3;
	double Average;

	printf("Enter three integers.\n");
	scanf("%d %d %d", &Blank1,&Blank2,&Blank3);

	Average = (double)(Blank1 + Blank2 + Blank3) / 3; //평균값 계산
	printf("The average of %d, %d, %d is %.3lf.\n", Blank1, Blank2, Blank3, Average);
	return 0;

}