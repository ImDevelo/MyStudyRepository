/* < C programing >                           Day 2019. 06. 01
 Project Title: Assignment 11. (12-6)
 Contents: 특정 문자열을 다른문자열로 대체하는 프로그램을 만들
 어라.                                                      */
#include<stdio.h>
#include<string.h>

//해당 문자열 change
void change_str(char *str, const char *to, const char *from) {
	char* There;
	int line = strlen(to);
	
	//해당문자열 교체
	while (1){
		There = strstr(str, to);
		if (There == NULL)
			return;
		strncpy(There, from, line);
	}
}

int main() {
	char str[100], st_f[40], st_t[40];
	char* text;

	//입력
	printf("Enter a string.\n");
	scanf("%[^\n]s", str);
	printf("from sring.\n");
	scanf("%s", st_f);
	printf("to string.\n");
	scanf("%s", st_t);

	change_str(str, st_f, st_t);
	//출력
	printf("%s", str);
	return 0;
}