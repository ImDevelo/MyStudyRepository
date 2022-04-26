#include<stdio.h>
#include<string.h>

char* my_strcat(char *dest, char *src) {
	char* str = dest;
	int i, j;
	for (i = 0; dest[i] != '\0'; i++);
	for (j=0; src[j-1] != '\0'; j++) {
		dest[i++] = src[j];
	}
	return dest;
}

int main() {
	char dest[100], src[100];

	while (1) {
		printf("Enter destination string.\n");
		scanf("%s", dest);
		if (strcmp(dest, "quit") == 0)
			break;
		printf("Enter source string.\n");
		scanf("%s", src);

		printf("%s\n", my_strcat(dest, src));
	}
}