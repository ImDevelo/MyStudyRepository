/* < C programing >                                Day 2019. 05. 11
 Project Title: Assignment 8. (10-2)
 Contents: -1�� ������ ������ �Ϸ��� ���� ���� �� ã�����ϴ� ����
 �� �Է¹޾� �ش������� � �ִ��� ã�Ƴ��� ����Լ��� �ۼ��϶�  */
#include<stdio.h>
#define MAX 100

// �������� ã�� ����
int count(const int arr[], const int comp, int last) {
	static int sum = 0;
	if (last == -1)
		return sum;
	else {
		if (arr[last] == comp)
			sum++;
		count(arr, comp, last - 1);
	}
}

int main() {
	int a[MAX];
	int Num;
	int i;

	printf("Enter input numbers.\n");
	for (i = 0; a[i - 1] != -1; i++) //�Ϸ��� ���� �Է�
		scanf("%d", &a[i]);
	printf("Enter a number to search.\n");//ã�����ϴ� ���� �Է�
	scanf("%d", &Num);
	printf("%d apeear %d times.\n", Num, count(a, Num, i - 2));
	return 0;
}