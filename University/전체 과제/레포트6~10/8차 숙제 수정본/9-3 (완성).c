/* < C programing >                           Day 2019. 05. 11
 Project Title: Assignment 8. (9-3)
 Contents: �Է¹��� ������ ȸ������ �Ǻ��Ϸ���               */
#include<stdio.h>
#define MAX 100

int main() {
	char A[MAX];
	int i, j;
	int State; 

	while (1) {
		printf("Enter a sentence.\n");
		State = 0; //State 0���� �ʱ�ȭ
		//�Է�
		for (i = 0; A[i - 1] != '\n'; i++) {
			A[i] = getchar();
			if (A[i-1] == 'Q')
				exit(1);
		}

		//ȸ������ �Ǻ�
		for (j = 0; j < (i-1) / 2; j++) {
			if (A[j] != A[i - 2 - j]) {
				State = 1; //ȸ���� �ƴ϶�� State 1
				break;
			}
		}

		if (State == 0)
			printf("Yes, it is a palindrome.\n");
		else
			printf("No, it is Not a palindrome.\n");
	}
}