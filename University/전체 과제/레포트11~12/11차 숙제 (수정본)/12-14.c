/* < C programing >                          Day 2019. 06. 01
 Project Title: Assignment 11. (12-14)
 Contents: ��ĭ�� ä�� ���ڸ� atoi�� ������ �ٲٰ� arr�� �д�
 ���α׷��� ������                                       */
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
		str = (char*)realloc(str, (i + 1) * sizeof(char));//str �Ҵ�
		str[i] = ch;
	}
	str[i] = ' ';
	str[i + 1] = '\n';

	ptr = strtok(str, " ");//stroke�� ��ũ
	while (ptr != NULL)
		ptr = strtok(NULL, " ");

	ptr = str;
	arr = NULL;
	for (i = 0; *ptr != '\n'; i++) {
		arr = (int*)realloc(arr, (i + 1) * sizeof(int));//arr�ڸ� �Ҵ�
		arr[i] = atoi(ptr);//atoi�� ���������� �ٲپ� arr�� ����
		while (*ptr != '\0')//str�� �������ڸ� ����Ŵ
			ptr++;
		ptr++;
	}
	for (j = 0; j < i; j++)
		printf("%d ", arr[j]);

	printf("\n");
	return 0;
}