/* < C programing >                              Day 2019. 05. 24
 Project Title: Assignment 10. (11-9)
 Contents: %s�������� ���ڿ��� �Է¹޾� ���� �迭�� �����ϰ� ��
 �� �Լ��� �Ἥ �װ��� �Ųٷ� ����϶� �� ���Լ��� ����Լ��� ��
 �ÿ� ������ ��������� �Ἥ �����ؾߵȴ�.                     */
#include<stdio.h>
#define MAX 100
//�Ųٷ� ����ϴ� �Լ�
void print_array(char *arr, int lenght) {
	if (lenght == 0)
		return;
	else {
		printf("%c", *(arr + lenght - 1));
		print_array(arr, --lenght);
	}
}

int main() {
	char str[MAX]; int i;
	printf("Enter the string.\n");
	scanf("%[^\n]s", str); //'\n'�Է¹ޱ������� �Է�
	for (i = 0; str[i] != '\0'; i++); //���ڿ� ����
	print_array(str, i);
}