/* < C programing >                          Day 2019. 06. 01
 Project Title: Assignment 11. (12-14)
 Contents: 빈칸을 채워 문자를 atoi로 정수로 바꾸고 arr로 읽는
 프로그램을 만들어라                                       */
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
		str = (char*)realloc(str, (i + 1) * sizeof(char));//str 할당
		str[i] = ch;
	}
	str[i] = ' ';
	str[i + 1] = '\n';

	ptr = strtok(str, " ");//stroke로 토크
	while (ptr != NULL)
		ptr = strtok(NULL, " ");

	ptr = str;
	arr = NULL;
	for (i = 0; *ptr != '\n'; i++) {
		arr = (int*)realloc(arr, (i + 1) * sizeof(int));//arr자리 할당
		arr[i] = atoi(ptr);//atoi로 정수값으로 바꾸어 arr에 대입
		while (*ptr != '\0')//str의 다음문자를 가르킴
			ptr++;
		ptr++;
	}
	for (j = 0; j < i; j++)
		printf("%d ", arr[j]);

	printf("\n");
	return 0;
}