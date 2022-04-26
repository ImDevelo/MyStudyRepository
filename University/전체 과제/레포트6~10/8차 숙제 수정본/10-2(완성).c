/* < C programing >                                Day 2019. 05. 11
 Project Title: Assignment 8. (10-2)
 Contents: -1이 들어오기 전까지 일련의 값을 받은 후 찾고자하는 정수
 를 입력받아 해당정수가 몇개 있는지 찾아내는 재귀함수를 작성하라  */
#include<stdio.h>
#define MAX 100

// 정수갯수 찾는 참수
int count(const int arr[], const int comp, int last) {
	static int sum = 0;
	if (last == -1)
		return sum;
	else {
		if (arr[last] == comp)
			sum++;
		count(arr, comp, last - 1);
	}
}

int main() {
	int a[MAX];
	int Num;
	int i;

	printf("Enter input numbers.\n");
	for (i = 0; a[i - 1] != -1; i++) //일련의 숫자 입력
		scanf("%d", &a[i]);
	printf("Enter a number to search.\n");//찾고자하는 숫자 입력
	scanf("%d", &Num);
	printf("%d apeear %d times.\n", Num, count(a, Num, i - 2));
	return 0;
}