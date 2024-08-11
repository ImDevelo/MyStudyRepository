/* < C programing >                                 Day 2019. 04. 04
 Project Title: Assignment 4. 5-5
 Contents:
점 p의 정수형 좌표값 x, y 를 입력받아 그 점이 속한 4분면(quadrant)을 
출력하는 프로그램을 작성하라. 단, 좌표축 경계선에 위치한 점은 입력하
지 않도록한다.                                                     */
#include <stdio.h>

// xy좌표값을 입력받아 4분면을 판별하는 함수
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
