/* < C programing >                                 Day 2019. 04. 04
 Project Title: Assignment 4. 5-6
 Contents:
 ü�� ��⿡���� ���� ���� ������ ���� ���� ������ ������ ������ ����
 �� �򰡿� �ݿ��Ѵ�. ������ �ܼ�ȭ�Ͽ� 3���� ������ 1���� 10���� ����
 �� �� ��� ������ �޴� ������ ����� ����. ��, �� ������ ��� ���� 
 �ٸ� ������ �شٰ� �����϶�.                                       */
#include <stdio.h>
int Score_print(int a, int b, int c);

//������ 3���� ������ ���� ���� �ǵ� �Լ�
int Score_print(int a, int b, int c) {
	if ((a > b && b > c) || (a < b && b < c))
		a = c = 0;
	if ((b > a && a > c) || (b < a && a < c))
		b = c = 0;
	if ((a > c&& c > b) || (a < c&& c < b))
		b = a = 0;

	int total;
	total = a + b + c;
	printf("The player gets %d", total);
	return;
}

int main() {
	int Blank1, Blank2, Blank3;

	printf("Enter scores of three judges.\n");
	scanf("%d %d %d", &Blank1, &Blank2, &Blank3);
	
	Score_print(Blank1, Blank2, Blank3);
	return 0;
}