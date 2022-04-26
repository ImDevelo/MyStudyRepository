/* < C programing >                               Day 2019. 05. 24
 Project Title: Assignment 10. (11-13)
 Contents: 숫자를 입력받고 그중에서 가장 작은 값과 가장 큰 값을 출
 력하는 프로그램을 작성하라.                                    */
#include<stdio.h>
#define MAX 100
//가장 큰수와 가장 작은수를 max min에 자장하는 함수
void min_max(int *arr, int *min, int *max, int lenght) {
	int i;
	*min = *max = arr[0];
	for (i = 1; i < lenght; i++) {
		if (arr[i] > *max) {
			*max = arr[i];
		}
		else if (arr[i] < *min) {
			*min = arr[i];
		}
	}
}

int main() {
	int DATA[MAX];
	int num, i = 0;
	int min, max;
	printf("Enter a seqence of positive integer.\n");
	while (1) {//숫자 입력
		scanf("%d", &num);
		if (num <= 0)
			break;
		DATA[i++] = num;
	}
	min = max = DATA[0];
	min_max(DATA, &min, &max, i);
	printf("MInimum is %d, Maximum is %d", min, max);
	return 0;
}