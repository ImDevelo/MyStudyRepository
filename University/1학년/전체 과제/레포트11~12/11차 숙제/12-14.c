#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	char ch, *str, *ptr;
	int i, j;
	int *arr;
	printf("Enter one or more integers.\n");
	str = NULL;

	for (i = 0; (ch = getchar()) != '\n'; i++) {
		str = (char*)realloc(str,(i + 1)* sizeof(char));
		str[i] = ch;
	}
	str[i] = ' ';
	str[i + 1] = '\n';


	ptr = strtok(str, " ");
	while (ptr != NULL)
		ptr = strtok(NULL , " ");



	ptr = str;
	arr = NULL;
	for (i = 0; *ptr != '\n'; i++) {
		arr = (int*)realloc(arr, (i + 1) * sizeof(int));
		arr[i] = atoi(ptr);

		while (*ptr != '\0')
			ptr++;

			ptr++;
	}
	for (j = 0; j < i; j++)
		printf("%d ", arr[j]);

	printf("\n");
	return 0;
}