/* < C programing >                                   Day 2019. 03. 27
 Project Title: Assignment 3. 3-4
 Contents:
 초단위를 입력받아 그것을 시간, 분, 초 단위로 출력하는 프로그램을 작성
 하라.                                                                */
#include <stdio.h>

int main() {
	int Blank1, Time_s, Time_m, Time_h;

	printf("Enter seconds.\n");
	scanf("%d", &Blank1);

	Time_h = Blank1 / 60 / 60; //시간 계산식
	Time_m = (Blank1 - Time_h * 60 * 60) / 60; //분 계산식
	Time_s = (Blank1 - Time_h * 60) % 60; //초 계산식

	printf("It is %d hour, %d minutes, %d seconds.", Time_h, Time_m, Time_s);
	return 0;

}