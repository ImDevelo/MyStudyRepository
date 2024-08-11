/* < C programing >                            Day 2019. 05. 11
 Project Title: Assignment 8. (10-1)
 Contents: 입력된 문자열을 부분문자열을 모두 나열하는 프로그램을
 작성하라                                                     */
#include<stdio.h>

// 덧셈 함수
void add(const int a, const int b, int* p) {
	*p = a + b;
}
// 2+3 계산
int main() {
	const int sum = 0;
	const int *ptr = &sum;
	const int a = 2;
	const int b = 3;

	add(a, b, ptr);
	printf("%d + %d = %d", a, b, sum);

}

