/* < C programing >                            Day 2019. 05. 11
 Project Title: Assignment 8. (9-10)
 Contents: �Էµ� ���ڿ��� �κй��ڿ��� ��� �����ϴ� ���α׷���
 �ۼ��϶�                                                     */
#include<stdio.h>
#define MAX 100

int main() {
	char Sub[MAX];
	int ch,i, j, k;
	int Last =0;
	printf("Enter a string.\n");
	//�Է�
	for (ch = 0; Sub[ch - 1] != '\n'; ch++) {
		Sub[ch] = getchar();
	}
	Last = ch - 2;//���ڿ� ����
	//�κ� ���ڿ� ���
	for (i = 0; i <= Last;i++) {
		for (j = i; j <= Last;j++) {
			for (k = i; k <=j; k++) {
				printf("%c", Sub[k]);	
			}
			printf("\n");
		}
	}


	

}