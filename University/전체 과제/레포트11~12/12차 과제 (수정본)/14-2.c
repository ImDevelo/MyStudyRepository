/* < C programing >                                Day 2019. 06. 07
 Project Title: Assignment 12. (14-2)
 Contents: �Է��׽�Ʈ ���Ͽ� ������ ������ �Է��� ��, �װ��� ������
 �� ����ϴ� �������α׷��� �ϼ��϶�.                            */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
	char text[10][100];
	char buff[100];
	int i, j;

	FILE *fp = fopen("original.txt", "rt");
	if (fp == NULL) { //�� �׽�Ʈ
		printf("Error.\n");
		exit(1);
	}
	for (i = 0; fgets(buff, sizeof(buff), fp) != NULL; i++)
		strcpy(text[i], buff);//���۸� text�� ����
	if (feof(fp)!=1) {//fp�� ���ϳ��� �ƴ϶��
		printf("Error.\n");
		exit(1);
	}
	for (j = i - 1; j >= 0; j--)
		fputs(text[j],stdout); //j��� ���
	fclose(fp);//���� �ݱ�

}
