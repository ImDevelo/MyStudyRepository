/* < C programing >                           Day 2019. 05. 18
 Project Title: Assignment 9. (10-9)
 Contents: 12개의 일련의 숫자를 입력받고 찾고자하는 숫자를 입력
 받으면 2진탐색하여 해당숫자의 인덱스 번호를 알아내는 프로그램을
 만드시오.                                                    */
#include<stdio.h>
#include<ctype.h>
#define MAX 12
void swap(int*, int*);
void selection_sort(int arr[], int length);
int binary_search(int arr[], int lenght, int value, int first, int last);

//숫자 인덱스 값 판별
int binary_search(int arr[], int lenght, int value, int first, int last) {
	int middle;
	middle = (first + last) / 2;
	
	if (arr[middle] == value) {
		return middle + 1;
	}
	else if(first>last){
		return -1;
	}
	else if (arr[middle] < value) {
		binary_search(arr, lenght, value, middle + 1, last);
	}
	else if (arr[middle] > value){
		binary_search(arr, lenght, value, first, middle - 1);
	}
}


int main() {
	int i, num, index;
	int data[MAX];
	printf("Enter twelve integers.\n");
	for (i = 0; i < 12; i++) {//12개의 숫자 입력
		scanf("%d", &data[i]);
	}
	selection_sort(data, i);//오름차순 숫자 정렬

	printf("Enter data to be serched.\n");
	scanf("%d", &num);//찾는 숫자 입력
	index = binary_search(data, i, num, 0, 11);//인덱스값 반환

	if (index == -1)
		printf("No such data.\n");
	else
		printf("It is in index %d", index);
}

// 숫자 swap
void swap(int* p, int* q) {
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}
//입력된 숫자 정렬
void selection_sort(int arr[], int length) {
	int last, largest, current;
	for (last = length - 1; last > 0; last--) {
		largest = 0;
		for (current = 1; current <= last; current++) {
			if (arr[current] > arr[largest])
				largest = current;
		}
		swap(&arr[largest], &arr[last]);
	}
}

