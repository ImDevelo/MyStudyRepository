/* < C programing >                           Day 2019. 05. 02
 Project Title: Assignment 7. (8-7)
 Contents: 1 부터 n까지 숫자를 순차적으로 출력하는 프로그램 */
#include<stdio.h>
// 1 부터 n까지 숫자를 순차적으로 출력하는 함수
void print_up(int n) {
	if (n == 0)
		return;
	else {
		print_up(n - 1);
		printf("%d ", n);
	}
}

int main() {
	int num;
	printf("Enter the last integer.\n");
	scanf("%d", &num);
	print_up(num);
}
