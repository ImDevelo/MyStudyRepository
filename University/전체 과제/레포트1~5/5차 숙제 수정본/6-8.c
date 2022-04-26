#include<stdio.h>
int main() {
	int i, j, k, N, sum = 0, a = 0;
	printf("Enter a natural number\n");
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		a *= 10;
		a += 9;
		sum += a;
		
	}
	printf("The sum is %d", sum);
}