/* < C programing >                                 Day 2019. 03. 28
 Project Title: Assignment 3. 4-4
 Contents:
알파벳 소문자를 읽어 대문자로 변환하는 함수를 작성하고 main에서 그것
을 불러 확인하는 프로그램을 작성하라. 함수 원형은 char to_upper_case
(char ch);로 한다.                                                */
#include <stdio.h>
char to_upper_case(char ch);

//소문자 아스키코드값을 대문자값으로 바꾸는 함수
char to_upper_case(char ch){
	return ch - 32;
}

int main() {
	char Blank1;

	printf("알파벳 소문자를 입력하세요.\n");
	scanf("%c",&Blank1); 
	printf("소문자 %c의 대문자는 %c입니다.\n",Blank1, to_upper_case(Blank1));

	return 0;

}