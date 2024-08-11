/*  < C programing >                                 Day 2019. 03. 20
 Project Title:  Assignment 2. (2-8)
 Contents:
  scanf를 써서 영문이름 이니셜(Initial)을 입력받고 다시 printf를 써서
그것을 다시 화면에 출력하는 프로그램을 작성하라                    */

#include <stdio.h>

int main() {

	char Blank1, Blank2, Blank3;
	scanf("%c%c%c", &Blank1, &Blank2, &Blank3);
	printf("Initials of your name are %c, %c, and %c.\n", Blank1, Blank2, Blank3);
	return 0;

}