/* < C programing >                          Day 2019. 05. 18
 Project Title: Assignment 9. (11-2)
 Contents: ���������� ����                                 */
#include<stdio.h>
int main() {
	int num, *p, **q;
	//p�����͸� �̿��� 5�Է� ����
	p = &num;
	*p = 5;
	printf("*P is %d\n", *p);
	//q���������͸� �̿��� 5�Է� ����
	q = &p;
	**q = 5;
	printf("**p is %d\n", **q);
}