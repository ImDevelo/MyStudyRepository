/* < C programing >                           Day 2019. 05. 02
 Project Title: Assignment 7. (8-14)
 Contents: 재귀함수 -> 반복문으로 바꾸어라                   */
#include<stdio.h>

int main() {
	int num,i;
	printf("Enter a natural number.\n");
	scanf("%d", &num);
	for (i = num; i <= 10; i++) {
		printf("%d.\n", i);
	}
	return 0;
}