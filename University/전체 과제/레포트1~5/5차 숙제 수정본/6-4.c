#include<stdio.h>
int main() {
	int i, N;
	long double sum = 0;
	double a = 1, b=0, c=0;
	printf("Enter the number of term.\n");
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		b = (double)(2 * i - 1) / 4.0;
		c = a / b;
		sum += c;
		a = -a;
	}
	printf("PI evaluated to %d terms is %lf.", N, sum);
}