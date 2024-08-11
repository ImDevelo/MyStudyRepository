/* < C programing >                                 Day 2019. 04. 04
 Project Title: Assignment 4. 5-6
 Contents:
 체조 경기에서는 가장 낮은 점수와 가장 높은 점수를 제외한 나머지 점수
 만 평가에 반영한다. 문제를 단순화하여 3명의 심판이 1에서 10까지 점수
 를 줄 경우 선수가 받는 점수를 계산해 보라. 단, 세 심판이 모두 서로 
 다른 점수를 준다고 가정하라.                                       */
#include <stdio.h>
int Score_print(int a, int b, int c);

//선수의 3개의 점수에 대한 점수 판독 함수
int Score_print(int a, int b, int c) {
	if ((a > b && b > c) || (a < b && b < c))
		a = c = 0;
	if ((b > a && a > c) || (b < a && a < c))
		b = c = 0;
	if ((a > c&& c > b) || (a < c&& c < b))
		b = a = 0;

	int total;
	total = a + b + c;
	printf("The player gets %d", total);
	return;
}

int main() {
	int Blank1, Blank2, Blank3;

	printf("Enter scores of three judges.\n");
	scanf("%d %d %d", &Blank1, &Blank2, &Blank3);
	
	Score_print(Blank1, Blank2, Blank3);
	return 0;
}