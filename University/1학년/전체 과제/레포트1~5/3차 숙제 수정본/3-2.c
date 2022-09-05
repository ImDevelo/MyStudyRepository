/* < C programing >                                 Day 2019. 03. 27
 Project Title: Assignment 3. 3-2
 Contents:
 섭씨 온도 C라고 했을 때 그에 해당하는 화씨 온도 F는 F =(9/5)C + 32 
 로 표시된다. 섭씨를 화씨로 바꾸어 출력하는 프로그램을 작성하되 정수
 버전을 작성하라.                                                  */
#include <stdio.h>

int main() {
	int Blank1, FC;

	printf("Enter degrees in Celcius.\n");
	scanf("%d", &Blank1);

	FC = Blank1 * 9 / 5 + 32;
	printf("%d degrees in Celcius is %d deegrees in Fahrenheit.\n",Blank1, FC);
	return 0;
}