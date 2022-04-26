/* < C programing >                           Day 2019. 05. 18
 Project Title: Assignment 9. (10-9)
 Contents: 12���� �Ϸ��� ���ڸ� �Է¹ް� ã�����ϴ� ���ڸ� �Է�
 ������ 2��Ž���Ͽ� �ش������ �ε��� ��ȣ�� �˾Ƴ��� ���α׷���
 ����ÿ�.                                                    */
#include<stdio.h>
#include<ctype.h>
#define MAX 12
void swap(int*, int*);
void selection_sort(int arr[], int length);
int binary_search(int arr[], int lenght, int value, int first, int last);

//���� �ε��� �� �Ǻ�
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
	for (i = 0; i < 12; i++) {//12���� ���� �Է�
		scanf("%d", &data[i]);
	}
	selection_sort(data, i);//�������� ���� ����

	printf("Enter data to be serched.\n");
	scanf("%d", &num);//ã�� ���� �Է�
	index = binary_search(data, i, num, 0, 11);//�ε����� ��ȯ

	if (index == -1)
		printf("No such data.\n");
	else
		printf("It is in index %d", index);
}

// ���� swap
void swap(int* p, int* q) {
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}
//�Էµ� ���� ����
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

