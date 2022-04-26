//12-15
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char **argv) {
	char op = *argv[2];
	int N1 = atoi(argv[1]), N2 = atoi(argv[3]);
	//°è»ê±â
	switch (op){
	case '+':
		printf("%d + %d = %d", N1, N2, N1 + N2);
		break;
	case '-':
		printf("%d - %d = %d", N1, N2, N1 - N2);
		break;
	case '*':
		printf("%d * %d = %d", N1, N2, N1 * N2);
		break;
	case '/':
		printf("%d / %d = %d", N1, N2, N1 / N2);
		break;
	default:
		break;
	}

	return 0;
}