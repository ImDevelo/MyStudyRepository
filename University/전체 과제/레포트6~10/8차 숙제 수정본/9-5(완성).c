/* < C programing >                           Day 2019. 05. 11
 Project Title: Assignment 8. (9-5)
 Contents: ���忡 'e'�� �ִٸ� yes ���ٸ� 'No'�� ����϶� ��, '
 e'�� �׻� ���� �������� ���Եǰ� 'e'�� �������� �ִٸ� No�� ��
���ض� 'e'�� ��Ƽ�� ��Ȱ�� �ؾ��Ѵ�.                          */
#include<stdio.h>
#define MAX 100

int main() {
	char A[MAX];
	int i, j;
	int State = 0;
	//���ڿ� �Է�, ���������� '\n'�� ����� 'e'����
	printf("Enter the fist string.\n");
	for (i = 0;; i++) {
		A[i] = getchar();
		if (A[i] == '\n') {
			A[i] = 'e';
			break;
		}
	}
	//'e'�� �ִٸ� State 1�� ��ȯ, �� �������̸� just break;
	for (j = 0; ; j++) {
		if (A[j] == 'e') {
			if (j == i)
				break;
			State = 1;
			break;
		}
	}
	if (State == 1)
		printf("Yes");
	else
		printf("No");
}



