/* < C programing >                                 Day 2019. 03. 27
 Project Title: Assignment 3. 3-2
 Contents:
 ������ ������ �Է¹޾� ����� ���ϴ� ���α׷��� �ۼ��϶�. �� �����
 double�����μ� �Ҽ� ���� 3�ڸ����� ����ϱ�� �Ѵ�. �Է��� ���ٷ� ��
 ������ �Է� ���̴� ��ĭ���� �����ϱ�� �Ѵ�.                      */
#include <stdio.h>

int main() {
	int Blank1, Blank2, Blank3;
	double Average;

	printf("Enter three integers.\n");
	scanf("%d %d %d", &Blank1,&Blank2,&Blank3);

	Average = (double)(Blank1 + Blank2 + Blank3) / 3; //��հ� ���
	printf("The average of %d, %d, %d is %.3lf.\n", Blank1, Blank2, Blank3, Average);
	return 0;

}