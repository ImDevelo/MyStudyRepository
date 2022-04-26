/* < C programing >                               Day 2019. 06. 06
 Project Title: Assignment 12. (14-5)
 Contents: �Է¹��ڸ� ��ȣȭ�Ͽ� 2�� ������ encrypt.bin ������ �ۼ�
 �϶�. ��, ��ȣȭ ����� ���� ������                             */
#include<stdio.h>
#include<stdlib.h>
int main() {
	char ch;
	int key, count;

	FILE*fp = fopen("encrypt.bin", "w+b");
	if (fp == NULL) {
		fprintf(stderr, "Error writing a character.\n");
		exit(1);
	}

	printf("Enter key.\n");
	scanf("%d", &key);
	while ((key = getchar()) != '\n');

	printf("Enter texts to encrypt. \n");
	while ( (ch = getchar()) != '\n') { //'\n'�� �ƴ� ������
		ch = (ch + key) % 128; 
		count = fwrite((void*)&ch, sizeof(char), 1, fp); //2�� ���� ����
		if (count < 1) {
			fprintf(stderr, "Error while writing a character.\n");
			exit(1);
		}
	}

	rewind(fp);//�б� ��带 ���� ��ġ �����͸� ���� ó������ �ǵ���
	while (  fread((void*)&ch, sizeof(char), 1, fp)  ) {//2�������б� ch�޾Ƶ帲
		ch = (ch - key) % 128;//���� ���� ����
		if (ch < 0)
			ch += 128;
		fputc(ch, stdout);
	}

	if (feof(fp) != 1) {//fp�� ���ϳ��� �ƴ϶��
		printf("Error.\n");
		exit(1);
	}

	fclose(fp);//���� �ݱ�
	return 0;
}