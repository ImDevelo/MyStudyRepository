#include<stdio.h>
int main() {
	int a, sum;
	printf("Enter a sentence\n");
	for (a = getchar(); a == '\n'; a = getchar()) {
		switch (a)
		{
		case 'a':
			sum++;
			break;
		case 'u':
			sum++;
			break;
		case 'e':
			sum++;
			break;
		case 'i':
			sum++;
			break;
		case 'o':
			sum++;
			break;
		default:
			break;
		}
	}
	putchar(sum);
	return 0;
}