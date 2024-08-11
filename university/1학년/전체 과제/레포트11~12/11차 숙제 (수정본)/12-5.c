/* < C programing >                           Day 2019. 06. 01
 Project Title: Assignment 11. (12-5)
 Contents: my_strchar�Լ��� ������                        */
#include<stdio.h>
#include<string.h>
//strchr(); �Լ�
char *my_strchr(const char *str, int c) {
	char *str_chr = str;
	int i = 0, j = 0;

	while (str[i] != c) {//�ش� ���ڰ� ���ö� ���� ����
		if (str[i++] == '\0')
			return NULL;//���ٸ� NULL����
	}
	while (str[i] != '\0') {//���� ���� ������ ����
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
		//�Է�
		printf("Enter source string.\n");
		gets(str);
		if (strcmp(str, "quit") == 0)
			break;
		printf("Enter character to be searched.\n");
		scanf("%c", &ch);
		getchar();//����Ŭ����
	
		text = my_strchr(str, ch);
		(text == NULL) ? printf("No such charater.\n") : puts(text);
	}
}