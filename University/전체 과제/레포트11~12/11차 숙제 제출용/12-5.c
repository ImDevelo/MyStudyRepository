/* < C programing >                           Day 2019. 06. 01
 Project Title: Assignment 11. (12-5)
 Contents: my_strchar함수를 만들어라                        */
#include<stdio.h>
#include<string.h>
//strchr(); 함수
char *my_strchr(const char *str, int c) {
	char *str_chr = str;
	int i = 0, j = 0;

	while (str[i] != c) {//해당 문자가 나올때 까지 루프
		if (str[i++] == '\0')
			return NULL;//없다면 NULL리턴
	}
	while (str[i] != '\0') {//이후 문자 저장후 리턴
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
		//입력
		printf("Enter source string.\n");
		gets(str);
		if (strcmp(str, "quit") == 0)
			break;
		printf("Enter character to be searched.\n");
		scanf("%c", &ch);
		getchar();//버터클리어
	
		text = my_strchr(str, ch);
		(text == NULL) ? printf("No such charater.\n") : puts(text);
	}
}