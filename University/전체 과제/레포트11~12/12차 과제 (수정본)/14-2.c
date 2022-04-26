/* < C programing >                                Day 2019. 06. 07
 Project Title: Assignment 12. (14-2)
 Contents: 입력테스트 파일에 세줄의 문장을 입력한 후, 그것을 역순으
 로 출력하는 다음프로그램을 완성하라.                            */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
	char text[10][100];
	char buff[100];
	int i, j;

	FILE *fp = fopen("original.txt", "rt");
	if (fp == NULL) { //널 테스트
		printf("Error.\n");
		exit(1);
	}
	for (i = 0; fgets(buff, sizeof(buff), fp) != NULL; i++)
		strcpy(text[i], buff);//버퍼를 text에 복사
	if (feof(fp)!=1) {//fp가 파일끝이 아니라면
		printf("Error.\n");
		exit(1);
	}
	for (j = i - 1; j >= 0; j--)
		fputs(text[j],stdout); //j요소 출력
	fclose(fp);//파일 닫기

}
