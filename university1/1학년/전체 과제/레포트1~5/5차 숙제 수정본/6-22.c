/* < C programing >                             Day 2019. 04. 11
 Project Title: Assignment 5. (6-22)
 Contents:
 ���ڰ� 3, 6, 9�� �� �� �� ���ڰ� ���ö� ���� �� ������ŭ ��
 ���� ģ��. 1���� N���� ���ڿ� ���Ͽ� 369�� �� ����� ����� �ۼ�
 �϶�                                                          */
#include<stdio.h>
int Game_369(int);

int main() {
	int Number;

	printf("Enter a number.\n");
	scanf("%d", &Number);
	Game_369(Number);

	return 0;
}

//3 6 9�϶� '!'(�ڼ�)�� ����ϴ� �Լ�
int Game_369(int N) {
	int i, j, k;
	int In_Num; //10���� ���� ������ �����صδ� �Լ�
	int Point_369; // 3,6,9�� ����� ���� ����
    int save_Num; //i���� �����صδ� ����

	for (i = 1; i <= N; i++) {
		Point_369 = 0;// 369���� �ʱ�ȭ
		save_Num = i; //save_Num�� i�� ����

		//3,6,9 ������ Point_369 �� �߰�
		for (j = 1; ; j++) {
			In_Num = save_Num % 10;
			save_Num /= 10;
			if (In_Num == 3 || In_Num == 6 || In_Num == 9)
				Point_369++;
			if (save_Num == 0)
				break;
		}

		//'!'Ȥ�� ���� ���
		if (Point_369 > 0)
			for (k = 1; k <= Point_369; k++) {
				printf("!");
			}
		else if (Point_369 == 0) {
			printf("%d", i);
		}
		printf(" ");
	}
	return;
}