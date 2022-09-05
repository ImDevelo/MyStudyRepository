/* < C programing >                           Day 2019. 05. 11
 Project Title: Assignment 8. (9-3)
 Contents: 입력받은 문장이 회문인지 판별하려라               */
#include<stdio.h>
#define MAX 100

int main() {
	char A[MAX];
	int i, j;
	int State; 

	while (1) {
		printf("Enter a sentence.\n");
		State = 0; //State 0으로 초기화
		//입력
		for (i = 0; A[i - 1] != '\n'; i++) {
			A[i] = getchar();
			if (A[i-1] == 'Q')
				exit(1);
		}

		//회문인지 판별
		for (j = 0; j < (i-1) / 2; j++) {
			if (A[j] != A[i - 2 - j]) {
				State = 1; //회문이 아니라면 State 1
				break;
			}
		}

		if (State == 0)
			printf("Yes, it is a palindrome.\n");
		else
			printf("No, it is Not a palindrome.\n");
	}
}