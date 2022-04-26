/* < C programing >                            Day 2019. 05. 11
 Project Title: Assignment 8. (9-10)
 Contents: 입력된 문자열을 부분문자열을 모두 나열하는 프로그램을
 작성하라                                                     */
#include<stdio.h>
#define MAX 100

int main() {
	char Sub[MAX];
	int ch,i, j, k;
	int Last =0;
	printf("Enter a string.\n");
	//입력
	for (ch = 0; Sub[ch - 1] != '\n'; ch++) {
		Sub[ch] = getchar();
	}
	Last = ch - 2;//문자열 길이
	//부분 문자열 출력
	for (i = 0; i <= Last;i++) {
		for (j = i; j <= Last;j++) {
			for (k = i; k <=j; k++) {
				printf("%c", Sub[k]);	
			}
			printf("\n");
		}
	}


	

}