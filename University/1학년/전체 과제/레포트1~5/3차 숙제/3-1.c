/* < C programing >                                 Day 2019. 03. 27
 Project Title: Assignment 3. 3-1
 Contents:
두 개의 자연수를 입력받아 첫번째 수를 두번 째수로 나눈 몫과 나머지를
출력하라                                                          */
#include <stdio.h>

int main() {
	int Blank1, Blank2;

	printf("Enter dividend.\n");
	scanf("%d", &Blank1);
	printf("Enter divisor.\n");
	scanf("%d", &Blank2);

	printf("Quotient is %d. Remainder is %d.\n", Blank1 / Blank2, Blank1 % Blank2);
	return 0;
}
