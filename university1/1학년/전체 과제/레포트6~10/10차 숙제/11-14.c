/* < C programing >                                 Day 2019. 05. 24
 Project Title: Assignment 10. (11-14)
 Contents: 두 배열을 한 배열로 합병하여 정렬하는 함수를 작성하라. */
#include<stdio.h>
#include<stdlib.h>

int main() {
	int a, b;
	int *p, *q;
	int i;
	int *Merge;

	printf("Enter number of element in array.\n");
	scanf("%d", &a);
	printf("Enter data to be insered in array a. It must be in sorted order.\n");
	p = (int*)malloc(a*sizeof(int));
	for (i = 0; i < a; i++)
		scanf("%d", &*(p + i));

	printf("Enter number of element in array.\n");
	scanf("%d", &b);
	printf("Enter data to be insered in array b. It must be in sorted order.\n");
	q = (int*)malloc(b * sizeof(int));
	for (i = 0; i < b; i++)
		scanf("%d", &*(q + i));
	Merge = (int*)malloc((a + b) * sizeof(int));
	i = 0;
	while (i++ < a + b) {
		if (*p < *q) {
			*(Merge++) = *(p++);
		}
		else if (*p < *q) {
			*(Merge++) = *(q++);
		}
	}

	//반환
	free(p);
	free(q);
	free(Merge);
	p = q = NULL;
}