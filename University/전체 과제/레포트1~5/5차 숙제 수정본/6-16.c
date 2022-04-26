/* < C programing >                            Day 2019. 04. 11
 Project Title: Assignment 5. (6-16)
 Contents:
 atoi함수를 직접 짜는 프로그램을 작성하라. 숫자를 개별 문자형태
 로 읽은 후 그것을 정수로 변환하여 출력하는 것이다. 빈줄을 채워
 이 프로그램을 완성해보라.                                    */
#include<stdio.h>	

int main() {
	char ch; int sum = 0;
	int value;

	printf("Enter a natual number.\n");
	while (1){
		scanf("%c", &ch);
		if (ch == '\n')
			break;
		value = ch - 48;
		sum = sum * 10 + value;
	}
	printf("You entered %d in decimal.\n", sum);
	return 0;
}