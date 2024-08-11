/* < C programing >                                 Day 2019. 05. 24
 Project Title: Assignment 10. (11-14)
 Contents: 두 배열을 한 배열로 합병하여 정렬하는 함수를 작성하라. */
#include<stdio.h>
#include<stdlib.h>

 //합병하는 함수
void AAA(int *p, int *q, int a, int b, int *Merge) {
	int i, count1 = 0, count2 = 0;
	//한 배열을 모두 정렬 할 때까지 합병
	for (i = 0; ; i++) {
		if (*p <= *q) {
			*Merge++ = *p++;
			count1++;
		}
		else if (*p > *q) {
			*Merge++ = *q++;
			count2++;
		}
		if (count1 == a || count2 == b)
			break;
	}
	//남은 배열 합병
	if (count1 > count2) {
		for (i = 0; count2 != b; i++) {
			*Merge++ = *q++;
			count2++;
		}
	}
	else if (count1 < count2) {
		for (i = 0; count1 != a; i++) {
			*Merge++ = *p++;
			count1++;
		}
	}
}

int main() {
	int a_size, b_size, i;
	int *p, *q, *Merge;
	int *A, *B;
	//입력
	printf("Enter number of element in array.\n");
	scanf("%d", &a_size);
	printf("Enter data to be insered in array a. It must be in sorted order.\n");
	p = (int*)malloc(a_size *sizeof(int));
	for (i = 0; i < a_size; i++)
		scanf("%d", &*(p + i));

	printf("Enter number of element in array.\n");
	scanf("%d", &b_size);
	printf("Enter data to be insered in array b. It must be in sorted order.\n");
	q = (int*)malloc(b_size * sizeof(int));
	for (i = 0; i < b_size; i++)
		scanf("%d", &*(q + i));
	Merge = (int*)malloc((a_size + b_size) * sizeof(int));
	//합병
	AAA(p, q, a_size, b_size, Merge);
	
	//출력
	printf("Result of merging is,\n");
	for (i = 0; i < a_size + b_size; i++) {
		printf("%d ", Merge[i]);
	}

	//반환
	free(p);
	free(q);
	free(Merge);
	p = q = NULL;
}

