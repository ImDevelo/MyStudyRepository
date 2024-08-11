/* < C programing >                              Day 2019. 05. 24
 Project Title: Assignment 10. (11-9)
 Contents: %s형식으로 문자열을 입력받아 정적 배열에 저장하고 아
 래 함수를 써서 그것을 거꾸로 출력하라 단 이함수는 재귀함수인 동
 시에 포인터 산술연산을 써서 구현해야된다.                     */
#include<stdio.h>
#define MAX 100
//거꾸로 출력하는 함수
void print_array(char *arr, int lenght) {
	if (lenght == 0)
		return;
	else {
		printf("%c", *(arr + lenght - 1));
		print_array(arr, --lenght);
	}
}

int main() {
	char str[MAX]; int i;
	printf("Enter the string.\n");
	scanf("%[^\n]s", str); //'\n'입력받기전까지 입력
	for (i = 0; str[i] != '\0'; i++); //문자열 길이
	print_array(str, i);
}