/* < C programing >                            Day 2019. 05. 18
 Project Title: Assignment 8. (10-12)
 Contents: ���ڸ� �Է��ϰų� �����ϴ� ���α׷��� �ۼ��Ͻÿ�. ��
 �µ� ���ڵ��� �������� ���ĵǾ� �ϰ� ���Ұ� �ش� ���Ұ� ������
 Ȥ�� ������ ���� �����Ǿ���Ѵ� q�� �ԷµǸ� ���α׷��� ������
 ��.                                                         */
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define Exist 1
#define NonExist 0

int has_element(int value, int set[], const int *cp);
void add_element(int value, int set[], int *cp);
void delete_element(int value, int set[], int *cp);
void print_arr(const int set[], int count);
void swap(int*, int*);
void selection_sort(int arr[], int length);

int main() {
	char data[MAX];
	char ch, Type;
	int value, count = 0;

	while (1) {
		printf("Enter commands: a 5 adds 5 to the set, d 5 deletes 5 from the set.\n");
		// Type �Է�, value �Է�
		scanf("%c ", &Type);
		scanf("%d", &value);
		getchar();
		// Type�� ���� add delete exit�Ǻ�
		if (Type == 'q') //Type q _���α׷� ����
			break;
		else if (Type == 'a') //Type a _�Է�
			add_element(value, data, &count);
		else if (Type == 'd') //Type d _����
			delete_element(value, data, &count);

		print_arr(data, count);
		printf("\n\n");
	}
}

//���� �� ����: _set ���ο� value�� �ִٸ� 1, ���ٸ� 0
int has_element(int value, int set[], int *cp) {
	int i;
	for (i = 0; i < *cp; i++) {
		if (set[i] == value)
			return Exist;
	}
	return NonExist;
}

//�Է°� add
void add_element(int value, int set[], int *cp) {
	int Ext = has_element(value, set, cp);
	int N = *cp;
	//value�� ������ �ε����� �����ѵ� ����
	if (Ext == 0) {
		*cp += 1;
		set[N] = value;
		if (*cp > 1)
		selection_sort(set, N);
	}
}

//�Է°� delete 
void delete_element(int value, int set[], int *cp) {
	int Ext = has_element(value, set, cp);
	int N = *cp;
	// value�� ����Ȱ��� ã�� �����ϰ� �� ������ �迭�� ������ �ڸ��� �����ѵ� ����
	if (Ext == 1) {
		*cp -= 1;
		N -= 1;
		for (int a = 0; a <= N; a++) {
			if (set[a] == value)
				set[a] = set[N];
		}
		if (*cp > 0)
		selection_sort(set, N);
	}
}

//�迭 �� ����Լ�
void print_arr(const int set[], int count) {
	int i;
	for (i = 0; i < count; i++)
		printf("%d ", set[i]);
}

// �迭swap
void swap(int* p, int* q) {
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}
//�Է� ���� �������� ����
void selection_sort(int arr[], int length) {
	int last, largest, current;
	for (last = length; last > 0; last--) {
		largest = 0;
		for (current = 1; current <= last; current++) {
			if (arr[current] > arr[largest])
				largest = current;
		}
		swap(&arr[largest], &arr[last]);
	}
}