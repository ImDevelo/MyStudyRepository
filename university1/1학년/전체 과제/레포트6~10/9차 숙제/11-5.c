/* < C programing >                             Day 2019. 05. 18
 Project Title: Assignment 9. (11-5)
 Contents: 양의 정수를 입력받고 배열A에 저장한뒤 거꾸로 뒤집에 B
 배열에 삽입하는 함수를 작성하라                              */
#include<stdio.h>
#define MAX 100
void Print_arr(int *arr, int length);
void reverse_arry(int *a, int *b, int length);
// 배열 A값을 배열 B에 순서를 반대로하여 저장
void reverse_arry(int *a, int *b, int length) {
	int i = 0;
	while (i <= length) {
		b[i] = a[length - i];
		i++;
	}
}

int main() {
	int A[MAX], B[MAX];
	int i, j;
	printf("Enter a sequence of positive intefers.\n");
	//배열 A입력
	for (i = 0; ; i++) {
		scanf("%d", &A[i]);
		if (A[i] <= 0)
			break;
	}
	reverse_arry(A, B, i - 1);
	//배열B 출력
	for (j = 0; j < i; j++)
		printf("%d ", B[j]);
	printf("\n");
}