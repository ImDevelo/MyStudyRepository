#include<stdio.h>
#include<string.h>
#define true 1
#define false 0

char *my_strstr(const char *str1, const char *str2) {
	const char *temp1 = str1, *temp2 = str2;
	int i, length = (int)strlen(str2);
	int matched = false;

	while (str1!='\n'){
		if (*temp1 == *temp2) {
			matched = true;
			for (i = 0; i < length; i++) {
				if (*(temp1 + i) != *(temp2 + i)) {
					matched = false;
					break;
				}
			}
			if (matched == true)
				return temp1;
		}
		temp1++;

	}
	return NULL;
}

int main() {
	char string1[100], string2[100], *position;
	while (1){
		printf("Enter string 1. \n");
		gets(string1);

		if (strcmp(string1, "quit") == 0)
			break;

		printf("Enter string 2. \n");
		gets(string2);

		position = my_strstr(string1, string2);
		(position == NULL) ? printf("No such string.\n") : puts(position);
	}
	return 0;
}