/* < C programing >                                   Day 2019. 03. 27
 Project Title: Assignment 3. 3-4
 Contents:
 �ʴ����� �Է¹޾� �װ��� �ð�, ��, �� ������ ����ϴ� ���α׷��� �ۼ�
 �϶�.                                                                */
#include <stdio.h>

int main() {
	int Blank1, Time_s, Time_m, Time_h;

	printf("Enter seconds.\n");
	scanf("%d", &Blank1);

	Time_h = Blank1 / 60 / 60; //�ð� ����
	Time_m = (Blank1 - Time_h * 60 * 60) / 60; //�� ����
	Time_s = (Blank1 - Time_h * 60) % 60; //�� ����

	printf("It is %d hour, %d minutes, %d seconds.", Time_h, Time_m, Time_s);
	return 0;

}