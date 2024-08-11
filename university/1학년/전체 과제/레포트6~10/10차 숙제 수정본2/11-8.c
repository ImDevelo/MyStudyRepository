/* < C programing >                           Day 2019. 05. 24
 Project Title: Assignment 10. (11-8)
 Contents: 문자열을 swap하는 프로그램을 작성하라            */
#include<stdio.h>
#define MAX_LEN 100
//swap함수
void swap_string(char *a, char *b) {
	int i, temp[MAX_LEN];
	for (i = 0; *(a + i) != '\0'; i++)
		temp[i] = *(a + i);
	temp[i] = '\0';
	for (i = 0; *(b + i) != '\0'; i++)
		*(a + i) = *(b + i);
	a[i] = '\0';
	for (i = 0; temp[i] != '\0'; i++)
		*(b + i) = temp[i];
	b[i] = '\0';
}

int main() {
	int i; char ch, string1[MAX_LEN], string2[MAX_LEN];

	printf("Enter string 1.\n");
	for (i = 0; (ch = getchar()) != '\n'; i++)
		string1[i] = ch;
	string1[i] = '\0';
	printf("Enter string 2.\n");
	for (i = 0; (ch = getchar()) != '\n'; i++)
		string2[i] = ch;
	string2[i] = '\0';

	swap_string(string1, string2);
	printf("After swapping.\n");
	printf("string 1 is %s\n", string1);

	printf("string 2 is %s\n", string2);
	return 0;
}