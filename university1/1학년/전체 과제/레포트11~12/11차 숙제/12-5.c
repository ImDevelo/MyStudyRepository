#include<stdio.h>
#include<string.h>


char *my_strchr(const char *str, int c) {
	char *str_chr = str;
	int i = 0, j = 0;

	while (str[i] != c) {
		if (str[i++] == '\n')
			return NULL;
	}
	while (str[i] != '\n') {
		str_chr[j++] = str[i];
		i++;
	}
	str_chr[j] = '\0';
	return str_chr;
}


int main() {
	char str[100];
	char ch;
	char* text;

	while (1){
		printf("Enter source string.\n");
		fgets(str,sizeof(str),stdin);
		if (strcmp(str, "quit") == 0)
			break;
		printf("Enter character to be searched.\n");
		scanf("%c", &ch);
		getchar();
	
		text = my_strchr(str, ch);
		if (text == NULL)
			printf("No such charater.\n");
		else
			printf("%s\n", text);

	}
}