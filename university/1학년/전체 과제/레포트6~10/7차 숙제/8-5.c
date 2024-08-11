/* < C programing >                           Day 2019. 05. 02
 Project Title: Assignment 7. (8-5)
 Contents:
 재귀호출함수: 1-N 까지의 합                                */
#include<stdio.h>
// 1-N 까지의 합 재귀호출 함수
int Sum_N(int n) {
	static int sum=0;
	if (n == 0)
		return sum;
	else{
		sum += n;
		Sum_N(n - 1);
	}
}

int main() {
	int Num;
	printf("Enter a number\n");
	scanf("%d", &Num);
	printf("Sum form 1 to %d is %d", Num, Sum_N(Num));
}