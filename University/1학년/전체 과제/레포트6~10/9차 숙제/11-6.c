/* < C programing >                             Day 2019. 05. 18
 Project Title: Assignment 9. (11-6)
 Contents: 11-5를 malloc를 이용하여 만들어라                  */
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
//순서 Cange
int* reverse_arry(int *a, int lenght) {
	int *p;
	int i = 0;
	p = (int *)malloc(lenght * sizeof(int));//동적 메모리
	if (p != NULL) {
		while (i < lenght) {
			p[i] = a[lenght-1-i];
			i++;
		}
	}
	return p;
}
//주어진 main함수
int main() {
	int i = 0, num, lenght; 
	int original[MAX], *reversed;
	printf("Enter a sequence of positive integers.\n");
	while (1) {
		scanf("%d", &num);
		if (num <= 0)
			break;
		original[i++] = num;
	}
	lenght = i;

	reversed = reverse_arry(original, lenght);
	for (i = 0; i < lenght; i++)
		printf("%d ", reversed[i]);
	printf("\n");
	free(reversed);
	return 0;
}



















/*
void reverse_arry(int *a, int *b, int length) {
	int *p;
	int i = 0;
	p = a;
	while (i <= length) {
		*(b + i) = *(p + length - i);
		i++;
	}
}
void Print_arr(int *arr, int length) {
	int i;
	for (i = 0; i < length; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int main() {
	int A[MAX], B[MAX];
	int i;
	for (i = 0; ; i++) {
		scanf("%d", &A[i]);
		if (A[i] <= 0)
			break;
	}
	Print_arr(A, i);
	reverse_arry(A, B, i - 1);
	Print_arr(B, i);
}
*/