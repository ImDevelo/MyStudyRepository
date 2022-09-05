/* < C programing >                            Day 2019. 04. 11
 Project Title: Assignment 5. (6-14)
 Contents:
 입력 자연수를 반대로 출력하는 프로그램을 작성하라. 단, 이 프로
 그램은 0이나 음수를 입력될 때까지 계속 반복되어야한다.       */
#include<stdio.h>
void reverse_it(int);

int main() {
	int Num;
	 while(1){
		 printf("Enter a natual number.\n");
		 scanf("%d",&Num);

		 if (Num <= 0)
			 break;
		 reverse_it(Num);
		 printf("\n");
		}
}

//자릿수를 반대로 출력하는 함수
void reverse_it(int num) {
	
	while (num > 0) {
		printf("%d", num % 10);
		num /= 10;
	}
	
	return;
}