/* < C programing >                              Day 2019. 04. 11
 Project Title: Assignment 5. (6-11)
 Contents:
 '서로 수'는 1이외에는 공약수가 없는 상태를 말한다. 두정수 a,b가
 인자로 전달될 때 서로 소라면 문자'y'를 그렇지 않으면'n'을 리턴하
 는 함수를 작성하고 main에서 그것을 불러 결과를 출력하는 프로그램
 을 작성하라,                                                  */
#include<stdio.h>
char mutally_prime(int a, int b);
int main() {
	int a, b;
	printf("Enter two numbers.\n");
	scanf("%d %d", &a, &b);
	if (mutally_prime(a, b) == 'y')
		printf("They are mutually prime.");
	if (mutally_prime(a, b) == 'n')
		printf("They are 'Not' mutually prime.");
}

//두 수가 서로소인지 판별하는 함수
char mutally_prime(int a, int b) { 
	int Lower_num, i;

	if (a < b) {
		Lower_num = a;
	}
	else if (a > b) {
		Lower_num = b;
	}

	for (i = 2; i <= Lower_num; i++) {
		if (a % i == 0&& b % i == 0)
			return 'n';
		else
			continue;
	}
	return 'y'; 
}
