/* < C programing >                                 Day 2019. 04. 04
 Project Title: Assignment 4. 5-11
 Contents:
 �����̶� 2���� 29�ϱ��� �ִ� �ظ� ���Ѵ�. �̴� 4�� ������ ����������
 100���� ������ �������� �ʰų� 4�� ������ �������� ���ÿ� 400���� ��
 ��������� �ظ� ���Ѵ�. �Ʒ� �Լ��� ����Ͽ� ������ �־��� �� ����
 ���� �ƴ����� ����ϴ� ���α׷��� �ۼ��϶�.                       */
#include <stdio.h>
int leap_year(int i);

int main() {
	int Blank;
	printf("Enter year\n");
	scanf("%d", &Blank);
	leap_year(Blank);
	return 0;
}

int leap_year(int i) {
	int Case_A, Case_B, Case_C;
	Case_A = i % 4;
	Case_B = i % 100;
	Case_C = i % 400;
	if (Case_A == 0 && Case_B != 0)
		printf("It is a leap year");
	else if (Case_A == 0 && Case_C == 0)
		printf("It is a leap year");
	else
		printf("It is not leap year");
	return;

}