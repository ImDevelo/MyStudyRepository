/*<C programing >                             Day 2019. 05. 11
Project Title : Assignment 8. (10 - 4)
Contents : abc�������� �Է¹ް� �����϶�                    */
#include<stdio.h>
//���� �Լ�
void cyclic_swap(int *a, int *b, int *c) {
	int temp;
	temp = *a;
	*a = *c;
	*c = *b;
	*b = temp;
}

int main() {
	int a, b, c;
	
	printf("Enter three interger.\n");
	scanf("%d%d%d", &a, &b, &c);
	printf("Before cyclic swap, a = %d, b = %d, c = %d.\n", a, b, c);//������
	cyclic_swap(&a, &b, &c);
	printf("Before cyclic swap, a = %d, b = %d, c = %d.\n", a, b, c);//������
	return 0;
}