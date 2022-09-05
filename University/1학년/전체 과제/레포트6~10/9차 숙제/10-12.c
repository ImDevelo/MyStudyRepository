/* < C programing >                            Day 2019. 05. 18
 Project Title: Assignment 8. (10-12)
 Contents: 숫자를 입력하거나 삭제하는 프로그램을 작성하시오. 입
 력된 숫자들은 오름차순 정렬되야 하고 원소가 해당 원소가 없을때
 혹은 있을때 삽입 삭제되어야한다 q가 입력되면 프로그램을 종료한
 다.                                                         */
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
		// Type 입력, value 입력
		scanf("%c ", &Type);
		scanf("%d", &value);
		getchar();
		// Type에 따른 add delete exit판별
		if (Type == 'q') //Type q _프로그램 종료
			break;
		else if (Type == 'a') //Type a _입력
			add_element(value, data, &count);
		else if (Type == 'd') //Type d _삭제
			delete_element(value, data, &count);

		print_arr(data, count);
		printf("\n\n");
	}
}

//같은 값 제외: _set 내부에 value가 있다면 1, 없다면 0
int has_element(int value, int set[], int *cp) {
	int i;
	for (i = 0; i < *cp; i++) {
		if (set[i] == value)
			return Exist;
	}
	return NonExist;
}

//입력값 add
void add_element(int value, int set[], int *cp) {
	int Ext = has_element(value, set, cp);
	int N = *cp;
	//value를 마지막 인덱스에 삽입한뒤 정렬
	if (Ext == 0) {
		*cp += 1;
		set[N] = value;
		if (*cp > 1)
		selection_sort(set, N);
	}
}

//입력값 delete 
void delete_element(int value, int set[], int *cp) {
	int Ext = has_element(value, set, cp);
	int N = *cp;
	// value가 저장된값을 찾고 삭제하고 맨 마지막 배열을 삭제된 자리에 삽입한뒤 정렬
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

//배열 값 출력함수
void print_arr(const int set[], int count) {
	int i;
	for (i = 0; i < count; i++)
		printf("%d ", set[i]);
}

// 배열swap
void swap(int* p, int* q) {
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}
//입력 숫자 오름차순 정렬
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