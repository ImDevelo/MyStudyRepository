/* < C programing >                           Day 2019. 05. 18
 Project Title: Assignment 9. (11-4)
 Contents: ������ ��������� �˻��ϴ� ���α׷��� ����ÿ�. */
#include<stdio.h>
//���� �Ǻ�
int count_vowel(char * arr, int lenght) {
	int sum = 0, i;//sum�� �������� ����
	for (i = 0; i < lenght; i++) {
		if (*(arr + i) == 'a' || *(arr + i) == 'e' || *(arr + i) == 'u' || *(arr + i) == 'i' || *(arr + i) == 'o')
			sum++;
	}
	return sum;
}

int main() {
	char ch, arr[100];
	int i = 0;
	printf("Enter the srntence.\n");
	while ((ch = getchar()) != '\n') { //�Է�
		arr[i++] = ch;
	}
	printf("vowel is %d", count_vowel(arr, i));
	return 0;
}