/* < C programing >                               Day 2019. 05. 24
 Project Title: Assignment 10. (11-13)
 Contents: ���ڸ� �Է¹ް� ���߿��� ���� ���� ���� ���� ū ���� ��
 ���ϴ� ���α׷��� �ۼ��϶�.                                    */
#include<stdio.h>
#define MAX 100
//���� ū���� ���� �������� max min�� �����ϴ� �Լ�
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
	while (1) {//���� �Է�
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