/* < C programing >                           Day 2019. 05. 02
 Project Title: Assignment 7. (8-15)
 Contents: ���� 8-22�� ���α׷� ���� ����ð��� ����϶�    */
#include<stdio.h>
#include<time.h>

//�ǰ�ġ���� �Լ�
long long fid(long long n) {
	if (n < 3)
		return 1;
	else
		return ((long long)(fid(n - 1) + fid(n - 2)));
}

int main() {
	long long num, result;
	clock_t start, end;//�������� ������ ����
	printf("Enter a number N.\n");
	scanf("%lld", &num);

	start = clock();//����
	result = fid(num);
	end = clock();//����
	printf("%lld th fibonacci number is %lld.\n", num, result);
	printf("Time elapsed for fibonacci is %.3f second\n", (float)(end - start) / CLOCKS_PER_SEC);// (����-����)�ð� ���
	return 0;
}