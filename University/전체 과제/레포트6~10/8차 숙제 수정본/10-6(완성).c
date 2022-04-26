/* < C programing >                           Day 2019. 05. 11
 Project Title: Assignment 8. (10-6)
 Contents:입력문장을 거꾸로 출력하는 프로그램을 작성하라    */
#include<stdio.h>
//문장 거꾸로 출력하는 프로그램
void reverse(char s[], int last) {
	if (last == -1) {
		return;
	}
	else {
		printf("%c", s[last]);
		reverse(s, last - 1);
	}
}
int main() {
	char S[100];
	int i = 0;
	printf("Enter the string.\n");
	while ((S[i] = getchar()) != '\n')//입력하여 배열에 저장
		i++;
	reverse(S, i - 1);

}