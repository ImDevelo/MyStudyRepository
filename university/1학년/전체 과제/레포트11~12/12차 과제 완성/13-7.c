/* < C programing >                             Day 2019. 06. 06
 Project Title: Assignment 12. (13-6)
 Contents: 입력받은 관광지 세개의 정보를 모두 출력하는 프로그램을
 작성하라                                                      */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char *name; //관광지 이름
	char rating; //등급: 'A', 'B', 'C'로 평가
}siteType;

int main() {
	int i; 
	char temp[100];
	siteType* sites[3]; //구조체를 가리키는 포인터배열

	for (i = 0; i < 3; i++) {
		sites[i] = (siteType *)malloc(sizeof(siteType)); //할당
		if (sites[i] == NULL) //널 테스트
			exit(1);
		printf("Enter name of the tour site.\n");
		gets(temp);
		sites[i]->name = (char *)malloc(strlen(temp)*sizeof(char));
		if (sites[i]->name == NULL) //널테스트
			exit(1);
		
		strcpy(sites[i]->name, temp);//문자열 복사
		printf("Enter rating of the tour site.\n");
		scanf("%c", &(sites[i]->rating));
		while ((getchar()) != '\n');//입력버퍼 클리어
	}
	for (i = 0; i < 3; i++)
		printf("%s %c\n", sites[i]->name, sites[i]->rating);
	return 0;
}
