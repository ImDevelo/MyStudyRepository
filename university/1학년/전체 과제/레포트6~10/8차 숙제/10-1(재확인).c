/* < C programing >                            Day 2019. 05. 11
 Project Title: Assignment 8. (10-1)
 Contents: �Էµ� ���ڿ��� �κй��ڿ��� ��� �����ϴ� ���α׷���
 �ۼ��϶�                                                     */
#include<stdio.h>

// ���� �Լ�
void add(const int a, const int b, int* p) {
	*p = a + b;
}
// 2+3 ���
int main() {
	const int sum = 0;
	const int *ptr = &sum;
	const int a = 2;
	const int b = 3;

	add(a, b, ptr);
	printf("%d + %d = %d", a, b, sum);

}

