/* < C programing >                            Day 2019. 05. 11
 Project Title: Assignment 8. (10-3)
 Contents: 피고나치수열 프로그램을 배열을 통해 보완하고 다음 빈
 칸을 채워 다음을 해결하여라                                 */
#include<stdio.h>
//피고나치 값 계산
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
	int i, num, value[100], found[100] = { 0 };//found 배열 초기화는 여기서
	scanf("%d", &num);
	//found 배열 초기화는 선언에서 마침
	value[0] = 1, value[1] = 1;
	found[0] = 1, found[1] = 1;

	printf("%dth Fibonacci number is %d,\n", num, fibo(value, found, num - 1));
	return 0;
}