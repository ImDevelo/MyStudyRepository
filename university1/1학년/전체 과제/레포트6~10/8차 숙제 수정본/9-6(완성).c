/* < C programing >                           Day 2019. 05. 11
 Project Title: Assignment 8. (9-6)
 Contents: 10���� 8���� �ĺ����� ��ǥ�Ͽ� �缱�ڸ� �˾Ƴ��� ����
 �׷��� ������. ��, ��ǥ���� ���ݼ��� �ƴ϶�� �缱�ڴ� ����.*/
#include <stdio.h>

int main() {
	int vote[10];
	int count[8] = { 0 };
	int i, j, k;
	int max = 0; // �ִ� ��ǥ��
	int Winner; //���� ��ȣ

	printf("Enter the result of voting.\n");
	for (i = 0; i < 10; i++) {
		scanf("%d", &vote[i]);//�Էº��� vote�� ����
		for (j = 0; j < 8; j++) {
			if (j == vote[i] - 1)
				count[j]++;//count�� vote ��ǥ �� ���
		}
	}
	//���� �Ǻ�
	for (k = 0; k < 8; k++) {
		if (max < count[k]) {
			Winner = k + 1;
			max = count[k];
		}
	}

	if (max >= 6)
		printf("Number %d is the winner.", Winner);
	else
		printf("There is no winner.");
	return 0;
}