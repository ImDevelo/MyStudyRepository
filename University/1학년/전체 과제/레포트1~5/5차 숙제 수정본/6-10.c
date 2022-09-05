#include<stdio.h>
#include<math.h>
int triangle(int, int, int);

int main() {
	int a, b, c, N;
	printf("Enter the maximum length N\n");
	scanf("%d", &N);
	printf("The the right-angled triangles are, \n");
	for (a = 1; a <= N; a++) {
		for (b = 1; b <= N; b++) {
			for (c = 1; c <= N; c++) {
				if (triangle(a, b, c))
					printf("%d %d %d \n", a, b, c);
			}
		}
	}
}

int triangle(int a, int b, int c) {
	int total;
	total = pow((double)c,2.0) == pow((double)a,2.0) + pow((double)b, 2.0);
	return total;
}