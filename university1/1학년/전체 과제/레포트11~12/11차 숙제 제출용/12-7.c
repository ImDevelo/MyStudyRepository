/* < C programing >                           Day 2019. 06. 01
 Project Title: Assignment 11. (12-7)
 Contents: strcmp를 만들어라                                */
#include<stdio.h>
#include<string.h>
int main() {
	char str1[100],str2[100];
	
	while (1) {
		printf("Enter string 1.\n");
		gets(str1);
		if (strcmp(str1, "quit") == 0)
			break;
		printf("Enter string 2.\n");
		gets(str2);
		printf("Result of strcmp(str1,str2) is %d.\n", my_stramp(str1,str2));
	}
	return 0;
}
//stramp함수
int my_stramp(const char *str1, const char *str2) {
	int i = 0;
	char a, b;
	while (1){
		a = str1[i], b = str2[i];//ab에 임시 저장
		if (a > b) 
			return 1;
		else if (a < b) 
			return -1;
		else if (a == '\0'&&b == '\0') 
			return 0;
		else if (a == '\0') 
			return -1;
		else if (b == '\0') 
			return 1;
		i++;
	}
}