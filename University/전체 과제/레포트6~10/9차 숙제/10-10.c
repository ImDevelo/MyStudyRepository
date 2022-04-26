/* < C programing >                          Day 2019. 05. 18
 Project Title: Assignment 9. (10-10)
 Contents: 회문인지 판단하는 프로그램을 작성하되 재귀함수를 호
 출하시오.                                                  */
#include<stdio.h>
#define MAX 100
//회문판별 함수
int is_palindrome(char s[], int first, int last) {
	if (first >= last)
		return 0;
	else if (first < last) {
		if (s[first] != s[last])
			return 1;
		is_palindrome(s, ++first, --last);
	}
}


int main() {
	char A[MAX], ch;
	int result,i = 0;

	while ((ch = getchar()) != '\n') {//문자 입력
		A[i] = ch;
		i++;
	}
	result = is_palindrome(A, 0, i-1);
	if (result == 0)
		printf("Yes, it is a plindrome.\n");
	else
		printf("No, it is NOT a plindrome.\n");
}
