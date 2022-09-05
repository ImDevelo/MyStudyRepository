#include<stdio.h>
int main() {
	int N, i, sum = 0;
	printf("Enter a maximum number.\n");
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		if (i % 5 == 0)
			continue;
		sum += i;
	}


	printf("The sum is %d\n", sum);
}