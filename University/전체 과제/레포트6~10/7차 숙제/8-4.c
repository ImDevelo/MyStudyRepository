/* < C programing >                           Day 2019. 05. 02
 Project Title: Assignment 7. (8-4)
 Contents: �ּڰ����                                       */
#include<stdio.h>	
int current_min(int n);      

//�ּڰ� �����ִ� �Լ�
int current_min(int n) {
	static int min = 100;
	if (n <= min)
		min = n;
	return min;
}

int main() {
	int Num;
	while (1) {
		printf("Enter a number.\n");
		scanf("%d", &Num);
		if (Num < 0) //�����϶� break;
			break;
		printf("Current min is %d\n",current_min(Num));
	}
	return 0;
}
