/* < C programing >                             Day 2019. 05. 24
 Project Title: Assignment 10. (11-15)
 Contents: 데이터를 입력받고 그것을 제곱한 값을 출력하는 프로그램
 을 작성하라                                                   */

#include<stdio.h>
#include<stdlib.h>

void destry_matrix(int** arr, int row);
int** create_matrix(int row, int col);
//동적배열 생성
int** create_matrix(int row, int col) {
	int i, **p;
	p = (int**)malloc(row* sizeof(int*));
	if (p == NULL)
		exit(1);
	for (i = 0; i < row; i++) {
		p[i] = (int*)malloc(col * sizeof(int));
		if (p[i] == NULL)
			exit(1);
	}
	return p;
}

int main() {
	int colum, row;
	int **Data;
	int i, j, num;

	printf("Enter row and colum.\n"); //행(가로), 열(세로) 입력;
	scanf("%d %d", &row, &colum);
	Data = create_matrix(row, colum);//동적배열 생성
	//숫자입력
	printf("Enter the value of array elements.\n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < colum; j++) {
			scanf("%d", &num);
			Data[i][j] = num * num;
		}
	}
	//결과출력
	printf("The result is\n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < colum; j++) {
			printf("%d ", Data[i][j]);
		}
		printf("\n");
	}
	destry_matrix(Data, row);//동적배열 환납
	return 0;
}

//반납
void destry_matrix(int** arr, int row) {
	int i;
	for (i = 0; i < row; i++) {
		free(arr[i]);
	}
	free(arr);
	arr = NULL;
}
