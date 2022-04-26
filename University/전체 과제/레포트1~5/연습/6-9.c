#include<stdio.h>
int main() {
	int N, i,X=0, sum = 0;
	printf("Enter the number\n");
	scanf("%d", &N);
	for (i = 1; i <= 4; i++) {
		
		X = N % 10;
		N = N/ 10;
		sum += X;
	}
	printf("The sum is %d", sum);
}