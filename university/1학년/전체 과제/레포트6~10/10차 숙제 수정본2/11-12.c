/* < C programing >                               Day 2019. 05. 24
 Project Title: Assignment 10. (11-12)
 Contents: main ���ڿ��� �����ϰ� ���ڿ��� ������ ������ �����Լ���
 ������ ��������� ����Ͽ� �ۼ��϶�                              */
#include<stdio.h>
//�Ųٷ� �Է�
void print_array(char *arr, int length) {
	int i = length - 1;
	while (i>=0){
		printf("%c", *(arr + i--));
	}
}
int main() {
	char arr[100];
	int i;
	printf("Enter the a sentense.\n");
	scanf("%[^\n]s", arr);
	for (i = 0; arr[i] != '\0'; i++);
	print_array(&arr, i);
	return 0;
}