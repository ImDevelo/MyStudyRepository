/* < C programing >                           Day 2019. 05. 24
 Project Title: Assignment 10. (11-17)
 Contents: 11-15�� �����Ͽ� ����� ���� ������            */
#include<stdio.h>

int main() {
	int i, j, k, h;
	int first[2][3], second[3][2], add[2][2];
	int sum1 = 1, sum2 = 1;

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			printf("Enter first matrix [%d][%d]: ", i, j);
			scanf("%d", &first[i][j]);
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			printf("Enter second matrix [%d][%d]: ", i, j);
			scanf("%d", &second[i][j]);
		}
	}

	//����� �� ���
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 3; k++)
				sum1 *= first[i][k];
			for (h = 0; h < 3; h++)
				sum2 *= second[h][j];
			add[i][j] = sum1 + sum2;
		}
	}
	//���
	printf("Sum of the two matrices is,\n");
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++)
			printf("%d ", add[i][j]);
		printf("\n");
	}
	return 0;
}
