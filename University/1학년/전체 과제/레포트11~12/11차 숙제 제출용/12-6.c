/* < C programing >                           Day 2019. 06. 01
 Project Title: Assignment 11. (12-6)
 Contents: Ư�� ���ڿ��� �ٸ����ڿ��� ��ü�ϴ� ���α׷��� ����
 ���.                                                      */
#include<stdio.h>
#include<string.h>

//�ش� ���ڿ� change
void change_str(char *str, const char *to, const char *from) {
	char* There;
	int line = strlen(to);
	
	//�ش繮�ڿ� ��ü
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

	//�Է�
	printf("Enter a string.\n");
	scanf("%[^\n]s", str);
	printf("from sring.\n");
	scanf("%s", st_f);
	printf("to string.\n");
	scanf("%s", st_t);

	change_str(str, st_f, st_t);
	//���
	printf("%s", str);
	return 0;
}