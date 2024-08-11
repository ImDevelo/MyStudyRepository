/* < C programing >                           Day 2019. 05. 18
 Project Title: Assignment 9. (10-11)
 Contents: 삽입정렬을 만들어라.                              */
#include<stdio.h>
#define MAX 100
void swap(int*, int*);
void insertion_sort(int arr[], int length);
void print_arr(const int arr[], int lenght);

int main() {
	int temp, i = 0;
	int data[MAX];
	printf("Enter input number.\n");
	while (1){ //숫자입력
		scanf("%d", &temp);
		if (temp<0)
			break;
		data[i++] = temp;
	}
	insertion_sort(data, i);
	printf("After sorting:");
	print_arr(data, i);
	printf("\n");
	return 0;
}
//삽입정렬: 입력된 숫자 정렬하는 함수
void insertion_sort(int arr[], int length) {
	int i, j;
	for (i = 1; i < length; i++) {
		for (j = 0; j < i ; j++) {
			if (arr[j] > arr[i]) {
				swap(&arr[j], &arr[i]);
			}
		}
	}
}

// swap 함수
void swap(int* p, int* q) {
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}
//정렬된 값 출력함수
void print_arr(const int arr[], int lenght) {
	int i;
	for (i = 0; i < lenght; i++)
		printf(" %d", arr[i]);
}
