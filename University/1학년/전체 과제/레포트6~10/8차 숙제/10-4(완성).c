/*<C programing >                             Day 2019. 05. 11
Project Title : Assignment 8. (10 - 4)
Contents : abc세정수를 입력받고 스왑하라                    */
#include<stdio.h>
//스왑 함수
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
	printf("Before cyclic swap, a = %d, b = %d, c = %d.\n", a, b, c);//스왑전
	cyclic_swap(&a, &b, &c);
	printf("Before cyclic swap, a = %d, b = %d, c = %d.\n", a, b, c);//스왑후
	return 0;
}