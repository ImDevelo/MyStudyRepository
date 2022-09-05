/* < C programing >                                 Day 2019. 04. 04
 Project Title: Assignment 4. 5-11
 Contents:
 윤년이란 2월이 29일까지 있는 해를 말한다. 이는 4로 나누어 떨어지지만
 100으로 나누어 떨어지지 않거나 4로 나누어 떨어지는 동시에 400으로 나
 누어떨어지는 해를 말한다. 아래 함수를 사용하여 연도를 주어질 때 윤년
 인지 아닌지를 출력하는 프로그램을 작성하라.                       */
#include <stdio.h>
int leap_year(int i);

int main() {
	int Blank;
	printf("Enter year\n");
	scanf("%d", &Blank);
	leap_year(Blank);
	return 0;
}

int leap_year(int i) {
	int Case_A, Case_B, Case_C;
	Case_A = i % 4;
	Case_B = i % 100;
	Case_C = i % 400;
	if (Case_A == 0 && Case_B != 0)
		printf("It is a leap year");
	else if (Case_A == 0 && Case_C == 0)
		printf("It is a leap year");
	else
		printf("It is not leap year");
	return;

}