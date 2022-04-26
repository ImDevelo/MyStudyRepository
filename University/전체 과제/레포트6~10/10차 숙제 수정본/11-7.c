/* < C programing >                           Day 2019. 05. 24
 Project Title: Assignment 10. (11-17)
 Contents: �迭�� ������ ���� swap�ϴ� ���α׷��� �ۼ��϶�  */
#include<stdio.h>
#define MAX 5
void print_array(int *arr, int lenght);
void swap_array(int *a, int *b, int lenght);

//�迭 ���
void print_array(int *arr, int lenght) {
	int i;
	for(i = 0; i < lenght; i++)
		printf("%d ", *(arr + i));
	printf("\n");
}
//�迭 swap
void swap_array(int *a, int *b, int lenght) {
	int temp, i;
	for (i = 0; i < lenght; i++) {
		temp = *(a + i);
		*(a + i) = *(b + i);
		*(b + i) = temp;
	}
}

int main() {
	int arr1[MAX], arr2[MAX];
	int leng = MAX, i;
	//�Է�
	printf("Enter the content of first array.\n");
	for (i = 0; i < 5; i++)
		scanf("%d", &arr1[i]);

	printf("Enter the content of second array.\n");
	for (i = 0; i < 5; i++)
		scanf("%d", &arr2[i]);

	//���
	//After print
	printf("Before swapping,\n");
	printf("first: ");
	print_array(arr1, leng);
	printf("second: ");
	print_array(arr2, leng);

	swap_array(arr1, arr2, leng);
	//After print
	printf("After swapping,\n");
	printf("first:");
	print_array(arr1, leng);
	printf("second:");
	print_array(arr2, leng);
}