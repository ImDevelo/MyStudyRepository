/* < C programing >                            Day 2019. 05. 11
 Project Title: Assignment 8. (10-3)
 Contents: �ǰ�ġ���� ���α׷��� �迭�� ���� �����ϰ� ���� ��
 ĭ�� ä�� ������ �ذ��Ͽ���                                 */
#include<stdio.h>
//�ǰ�ġ �� ���
int fibo(int val[], int fud[], int n) {
	int temp;
	if (fud[n] == 1)
		return val[n];
	else {
		temp = fibo(val, fud, n - 1) + fibo(val, fud, n - 2);
		val[n] = temp;
		fud[n] = 1;
		return temp;
	}
}
int main() {
	int i, num, value[100], found[100] = { 0 };//found �迭 �ʱ�ȭ�� ���⼭
	scanf("%d", &num);
	//found �迭 �ʱ�ȭ�� ���𿡼� ��ħ
	value[0] = 1, value[1] = 1;
	found[0] = 1, found[1] = 1;

	printf("%dth Fibonacci number is %d,\n", num, fibo(value, found, num - 1));
	return 0;
}