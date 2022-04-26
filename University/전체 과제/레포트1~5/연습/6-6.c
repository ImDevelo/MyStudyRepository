#include<stdio.h>	
int main() {
	int i;
	double n, sum=0;
	scanf("%lf", &n);
	for (i = 0; i < n; i++){
		sum += (1.0 / n);
	}
	printf("%lf", sum);
}