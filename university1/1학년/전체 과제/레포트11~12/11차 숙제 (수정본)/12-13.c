/* < C programing >                           Day 2019. 06. 01
 Project Title: Assignment 11. (12-13)
 Contents: strcpy�Լ��� ����Լ��� �����϶�.                */
#include<stdio.h>
#include<string.h>

// strcpy ���� ����Լ�
char *my_strcpy(char *dest, const char *src, int index) {
	if (src[index] == '\0') {
		dest[index] = '\0';
		return dest;
	}
	else {
		dest[index] = src[index];
		my_strcpy(dest, src, ++index);
	}
}

int main() {
	char dest[40],src[40];
	//�Է�
	printf("Enter destination string.\n");
	gets(dest);
	printf("Enter source string.\n");
	gets(src);
	//���
	puts(my_strcpy(dest, src, 0));
	return 0;
}