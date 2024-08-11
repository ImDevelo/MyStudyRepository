/* < C programing >                                  Day 2019. 03. 27
 Project Title: Assignment 3. 4-1
 Contents: 두정수를 입력받아 첫번째 정수가 두번째 정수보다 크거나 같으
 면 1을, 그렇지 않으면 0을 되돌려주는 함수를 작성하고 main에서 그 함수
 를 불러 결과를 출력하는 프로그램을 작성하라
함수 원형은 int is_latger(int f, int s);                            */
#include <stdio.h>
int is_latger(int f, int s);

//두 수를 비교하는 함수
int is_latger(int f, int s) {
	return f >= s;

}

int main() {
	int Blank1, Blank2;

	printf("Enter two integers.\n");
	scanf("%d %d", &Blank1,&Blank2);
	printf("Result is %d.", is_latger(Blank1, Blank2));
	return 0;

}