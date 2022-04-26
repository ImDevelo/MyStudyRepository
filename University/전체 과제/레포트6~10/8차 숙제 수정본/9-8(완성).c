/* < C programing >                           Day 2019. 05. 11
 Project Title: Assignment 8. (9-8)
 Contents: 두 문장을 입력 받고 두 문장이 서로 애너그램인지 판별
 하는 프로그램을 만들어라.                                   */
#include<stdio.h>
#define MAX 100

int main() {
	char A[MAX], B[MAX];
	int i, j, k, h;
	int State = 0;
	//입력1
	printf("Enter the fist string.\n");
	for (int a = 0; A[a - 1] != '\n'; a++) {
		A[a] = getchar();
	}
	//입력2
	printf("Enter the second string.\n");
	for (int b = 0; B[b - 1] != '\n'; b++) {
		B[b] = getchar();
	}

	//문자가 같으면 '*'로 치환
	for (i = 0; A[i] != '\n'; i++) {
		for (j = 0; B[j] != '\n'; j++) {
			if (A[i] == B[j]) {
				B[j] = '*';
				A[i] = '*';
				break;
			}
		}
	}

	//에너그램 판별
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
	//결과 출력
	if (State == 0)
		printf("Yes, they are anagrams.\n");
	else
		printf("No, they are not anagrams.\n");
	return 0;
}