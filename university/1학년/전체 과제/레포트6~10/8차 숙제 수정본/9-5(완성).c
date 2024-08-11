/* < C programing >                           Day 2019. 05. 11
 Project Title: Assignment 8. (9-5)
 Contents: 문장에 'e'가 있다면 yes 없다면 'No'를 출력하라 단, '
 e'는 항상 문장 마지막에 삽입되고 'e'가 마지막에 있다면 No를 출
력해라 'e'는 센티널 역활을 해야한다.                          */
#include<stdio.h>
#define MAX 100

int main() {
	char A[MAX];
	int i, j;
	int State = 0;
	//문자열 입력, 마지막에는 '\n'을 지우고 'e'대입
	printf("Enter the fist string.\n");
	for (i = 0;; i++) {
		A[i] = getchar();
		if (A[i] == '\n') {
			A[i] = 'e';
			break;
		}
	}
	//'e'가 있다면 State 1로 전환, 단 마지막이면 just break;
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



