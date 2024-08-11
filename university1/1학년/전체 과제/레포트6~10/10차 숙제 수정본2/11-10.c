/* < C programing >                              Day 2019. 05. 24
 Project Title: Assignment 10. (11-10)
 Contents: main 함수를 토대로 두함수를 채워라. 첫함수는 배열 기호
 를 둘째 함수는 포인터 산술연산을 사용하라.                     */
#include<stdio.h>
double average_by_array(int p[], int lenght);
double average_by_pointer(int *p, int lenght);

int main() {
	int arr[5] = { 10,40,50,20,15 };
	printf("%lf\n", average_by_array(arr,5));
	printf("%lf\n", average_by_pointer(arr,5));
	return 0;
}
//배열을 사용한 평균계산
double average_by_array(int p[], int lenght) {
	int sum = 0, i;
	for (i = 0; i < 5; i++)
		sum += p[i];
	return ((double)sum / lenght);
}
//포인터를 사용한 평균계산
double average_by_pointer(int *p, int lenght) {
	int sum = 0, i;
	for (i = 0; i < 5; i++)
		sum += *(p + i);
	return ((double)sum / lenght);
}
