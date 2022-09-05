/* < C programing >                            Day 2019. 04. 11
 Project Title: Assignment 5. (6-12)
 Contents:
  홀수n을 입력받아 아래모습을 출력하는 프로그램을 작성하라.    */
#include<stdio.h>
int print_piramid(int N);
int print_star(int N);
int print_number(int N);

int main() {
	int N;
	printf("Enter the number.\n");
	scanf("%d", &N);

	print_star(N);
	print_number(N);
	print_piramid(N);
	return 0;
}

//*찍기
int print_star(int N) {
	int i, j;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= i; j++)
			printf("*");
		printf("\n");
	}
}

//12345~찍기
int print_number(int N) {
	int x, y;
	for (x = 1; x <= N; x++) {
		for (y = 1; y <= x; y++)
			printf("%d", y);
		printf("\n");
	}
}

//피라미드 *찍기
int print_piramid(int N) {
	int i, j, k;
	for (i = 1; i <= (N / 2 + 1); i++) {
		for (j = 1; j <= N / 2 + 1 - i; j++)
			printf(" ");
		for (k = 1; k <= (2 * i - 1); k++)
			printf("*");
		printf("\n");
	}
}