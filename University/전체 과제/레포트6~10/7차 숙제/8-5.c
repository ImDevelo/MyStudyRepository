/* < C programing >                           Day 2019. 05. 02
 Project Title: Assignment 7. (8-5)
 Contents:
 ���ȣ���Լ�: 1-N ������ ��                                */
#include<stdio.h>
// 1-N ������ �� ���ȣ�� �Լ�
int Sum_N(int n) {
	static int sum=0;
	if (n == 0)
		return sum;
	else{
		sum += n;
		Sum_N(n - 1);
	}
}

int main() {
	int Num;
	printf("Enter a number\n");
	scanf("%d", &Num);
	printf("Sum form 1 to %d is %d", Num, Sum_N(Num));
}