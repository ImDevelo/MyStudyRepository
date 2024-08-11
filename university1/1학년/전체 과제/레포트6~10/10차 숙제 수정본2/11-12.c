/* < C programing >                               Day 2019. 05. 24
 Project Title: Assignment 10. (11-12)
 Contents: main 문자열을 저장하고 문자열의 순서를 뒤집는 제귀함수를
 포인터 산술연산을 사용하여 작성하라                              */
#include<stdio.h>
//거꾸로 입력
void print_array(char *arr, int length) {
	int i = length - 1;
	while (i>=0){
		printf("%c", *(arr + i--));
	}
}
int main() {
	char arr[100];
	int i;
	printf("Enter the a sentense.\n");
	scanf("%[^\n]s", arr);
	for (i = 0; arr[i] != '\0'; i++);
	print_array(&arr, i);
	return 0;
}