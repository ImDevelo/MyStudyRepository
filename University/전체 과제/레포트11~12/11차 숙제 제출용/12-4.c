/* < C programing >                           Day 2019. 06. 01
 Project Title: Assignment 11. (12-4)
 Contents: my_strcant를 만들어라                            */
#include<stdio.h>
#include<string.h>

//strcant();
char* my_strcat(char *dest, char *src) {
	char* str = dest;
	int i, j;
	for (i = 0; dest[i] != '\0'; i++);
	for (j=0; src[j-1] != '\0'; j++) { //이어붙이기
		dest[i++] = src[j];
	}
	return dest;
}

int main() {
	char dest[100], src[100];

	while (1) {
		printf("Enter destination string.\n");
		gets(dest);
		if (strcmp(dest, "quit") == 0)//break 조건
			break;
		printf("Enter source string.\n");
		gets(src);

		printf("%s\n", my_strcat(dest, src));
	}
}