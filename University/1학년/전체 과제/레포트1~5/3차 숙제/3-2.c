/* < C programing >                                 Day 2019. 03. 27
 Project Title: Assignment 3. 3-2
 Contents:
 ���� �µ� C��� ���� �� �׿� �ش��ϴ� ȭ�� �µ� F�� F =(9/5)C + 32 
 �� ǥ�õȴ�. ������ ȭ���� �ٲپ� ����ϴ� ���α׷��� �ۼ��ϵ� ����
 ������ �ۼ��϶�.                                                  */
#include <stdio.h>

int main() {
	int Blank1, FC;

	printf("Enter degrees in Celcius.\n");
	scanf("%d", &Blank1);

	FC = Blank1 * 9 / 5 + 32;
	printf("%d degrees in Celcius is %d deegrees in Fahrenheit.\n",Blank1, FC);
	return 0;
}