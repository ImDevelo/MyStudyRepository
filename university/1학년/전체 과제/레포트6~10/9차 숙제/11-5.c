/* < C programing >                             Day 2019. 05. 18
 Project Title: Assignment 9. (11-5)
 Contents: ���� ������ �Է¹ް� �迭A�� �����ѵ� �Ųٷ� ������ B
 �迭�� �����ϴ� �Լ��� �ۼ��϶�                              */
#include<stdio.h>
#define MAX 100
void Print_arr(int *arr, int length);
void reverse_arry(int *a, int *b, int length);
// �迭 A���� �迭 B�� ������ �ݴ���Ͽ� ����
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
	//�迭 A�Է�
	for (i = 0; ; i++) {
		scanf("%d", &A[i]);
		if (A[i] <= 0)
			break;
	}
	reverse_arry(A, B, i - 1);
	//�迭B ���
	for (j = 0; j < i; j++)
		printf("%d ", B[j]);
	printf("\n");
}