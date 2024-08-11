#include<stdio.h>
int main() {
	int N, i=1,sum=0;
	printf("Enter\n");
	scanf("%d", &N);
	while (sum < N) {
		sum += i++;
	}
	if (sum != N)
		sum -= i--;
	printf("THe sum from 1 to %d is %d", i-1, sum+1);
}