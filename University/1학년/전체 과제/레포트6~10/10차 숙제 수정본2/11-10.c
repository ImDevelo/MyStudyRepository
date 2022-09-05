/* < C programing >                              Day 2019. 05. 24
 Project Title: Assignment 10. (11-10)
 Contents: main �Լ��� ���� ���Լ��� ä����. ù�Լ��� �迭 ��ȣ
 �� ��° �Լ��� ������ ��������� ����϶�.                     */
#include<stdio.h>
double average_by_array(int p[], int lenght);
double average_by_pointer(int *p, int lenght);

int main() {
	int arr[5] = { 10,40,50,20,15 };
	printf("%lf\n", average_by_array(arr,5));
	printf("%lf\n", average_by_pointer(arr,5));
	return 0;
}
//�迭�� ����� ��հ��
double average_by_array(int p[], int lenght) {
	int sum = 0, i;
	for (i = 0; i < 5; i++)
		sum += p[i];
	return ((double)sum / lenght);
}
//�����͸� ����� ��հ��
double average_by_pointer(int *p, int lenght) {
	int sum = 0, i;
	for (i = 0; i < 5; i++)
		sum += *(p + i);
	return ((double)sum / lenght);
}
