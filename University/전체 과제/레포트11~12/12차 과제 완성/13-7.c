/* < C programing >                             Day 2019. 06. 06
 Project Title: Assignment 12. (13-6)
 Contents: �Է¹��� ������ ������ ������ ��� ����ϴ� ���α׷���
 �ۼ��϶�                                                      */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char *name; //������ �̸�
	char rating; //���: 'A', 'B', 'C'�� ��
}siteType;

int main() {
	int i; 
	char temp[100];
	siteType* sites[3]; //����ü�� ����Ű�� �����͹迭

	for (i = 0; i < 3; i++) {
		sites[i] = (siteType *)malloc(sizeof(siteType)); //�Ҵ�
		if (sites[i] == NULL) //�� �׽�Ʈ
			exit(1);
		printf("Enter name of the tour site.\n");
		gets(temp);
		sites[i]->name = (char *)malloc(strlen(temp)*sizeof(char));
		if (sites[i]->name == NULL) //���׽�Ʈ
			exit(1);
		
		strcpy(sites[i]->name, temp);//���ڿ� ����
		printf("Enter rating of the tour site.\n");
		scanf("%c", &(sites[i]->rating));
		while ((getchar()) != '\n');//�Է¹��� Ŭ����
	}
	for (i = 0; i < 3; i++)
		printf("%s %c\n", sites[i]->name, sites[i]->rating);
	return 0;
}
