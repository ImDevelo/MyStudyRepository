/* < C programing >                                 Day 2019. 04. 04
 Project Title: Assignment 4. 5-5
 Contents:
�� p�� ������ ��ǥ�� x, y �� �Է¹޾� �� ���� ���� 4�и�(quadrant)�� 
����ϴ� ���α׷��� �ۼ��϶�. ��, ��ǥ�� ��輱�� ��ġ�� ���� �Է���
�� �ʵ����Ѵ�.                                                     */
#include <stdio.h>

// xy��ǥ���� �Է¹޾� 4�и��� �Ǻ��ϴ� �Լ�
int Quart_print(int a, int b) {
	if (a > 0 && b > 0) {
		printf("It's in the 1th qruadrant.\n");
	}
	else if (a < 0 && b > 0) {
		printf("It's in the 2th qruadrant.\n");
	}
	else if (a < 0 && b < 0) {
		printf("It's in the 3th qruadrant.\n");
	}
	else if (a > 0 && b < 0) {
		printf("It's in the 4th qruadrant.\n");
	}
	else
		printf("Error!.\n");
	return;
}

int main() {
	int Blank1, Blank2;

	printf("Enter the x, y coodination of the point.\n");
	scanf("%d %d", &Blank1, &Blank2);
	
	Quart_print(Blank1, Blank2);
	return 0;
}
