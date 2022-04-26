#include<stdio.h>
#include<string.h>

int ch_3() {
	int 

	return ;
}




char *strstr_by_hash(const char *str1, const char *str2) {

	






	return NULL;
}

int main() {
	char text[60], S_txt[10];
	char* ret;
	printf("Enter text.\n");
	gets(text);
	printf("Enter serch string.\n");
	gets(S_txt);


	ret = strstr_by_hash(text, S_txt);
	(ret == NULL) ? printf("No such string.\n") : printf("%s gets polarized", ret);

	return 0;
}