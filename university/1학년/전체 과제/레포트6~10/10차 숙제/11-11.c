/* < C programing >                             Day 2019. 05. 24
 Project Title: Assignment 10. (11-11)
 Contents: recalloc을 사용하여 문자열을 swap하는 프로그램을 작성
 하라                                                         */
#include<stdio.h>
#include<stdint.h>
void swap(int *a, int *b);
int main() {
	int i; char ch, *temp;
	char **p = (char**)malloc(2 * sizeof(char*));

	p[1] = p[0] = NULL;

	printf("Enter first string.\n");
	for (i = 0; (ch = getchar()) != '\n'; i++) {
		p[0] = (char*)realloc(p[0], (i + 2) * sizeof(char));
		if (p[0] == NULL)
			exit(1);
		p[0][i] = ch;
		p[0][i+1] = '\0';
	}
	printf("Enter second string.\n");
	for (i = 0; (ch = getchar()) != '\n'; i++) {
		p[1] = (char*)realloc(p[1], (i + 2) * sizeof(char));
		if (p[1] == NULL)
			exit(1);
		p[1][i] = ch;
		p[1][i+1] = '\0';
	}
	swap(&p[0], &p[1]);
	printf("first string became %s, second string became %s.", p[0], p[1]);
	free(p[0]);
	free(p[1]);
	free(p);
	return 0;
}

void swap(int *a, int *b) {
	int* temp;
	temp = *a;
	*a = *b;
	*b = temp;
}