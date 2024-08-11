/* < C programing >                          Day 2019. 05. 18
 Project Title: Assignment 9. (11-2)
 Contents: 이중포인터 연습                                 */
#include<stdio.h>
int main() {
	int num, *p, **q;
	//p포인터를 이용한 5입력 저장
	p = &num;
	*p = 5;
	printf("*P is %d\n", *p);
	//q이중포인터를 이용한 5입력 저장
	q = &p;
	**q = 5;
	printf("**p is %d\n", **q);
}