/* < C programing >                           Day 2019. 05. 11
 Project Title: Assignment 8. (9-8)
 Contents: �� ������ �Է� �ް� �� ������ ���� �ֳʱ׷����� �Ǻ�
 �ϴ� ���α׷��� ������.                                   */
#include<stdio.h>
#define MAX 100

int main() {
	char A[MAX], B[MAX];
	int i, j, k, h;
	int State = 0;
	//�Է�1
	printf("Enter the fist string.\n");
	for (int a = 0; A[a - 1] != '\n'; a++) {
		A[a] = getchar();
	}
	//�Է�2
	printf("Enter the second string.\n");
	for (int b = 0; B[b - 1] != '\n'; b++) {
		B[b] = getchar();
	}

	//���ڰ� ������ '*'�� ġȯ
	for (i = 0; A[i] != '\n'; i++) {
		for (j = 0; B[j] != '\n'; j++) {
			if (A[i] == B[j]) {
				B[j] = '*';
				A[i] = '*';
				break;
			}
		}
	}

	//���ʱ׷� �Ǻ�
	for (k = 0; B[k] != '\n'; k++) {
		if (B[k] != '*') {
			if (B[k] == ' ')
				continue;
			State = 1;
			break;
		}
	}
	for (h = 0; A[h] != '\n'; h++) {
		if (A[h] != '*') {
			if (A[h] == ' ')
				continue;
			State = 1;
			break;
		}
	}
	//��� ���
	if (State == 0)
		printf("Yes, they are anagrams.\n");
	else
		printf("No, they are not anagrams.\n");
	return 0;
}