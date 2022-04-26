/* < C programing >                               Day 2019. 06. 06
 Project Title: Assignment 12. (14-5)
 Contents: 입력문자를 암호화하여 2진 파일인 encrypt.bin 파일을 작성
 하라. 단, 암호화 방식은 써저 사이퍼                             */
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
	while ( (ch = getchar()) != '\n') { //'\n'이 아닐 때까지
		ch = (ch + key) % 128; 
		count = fwrite((void*)&ch, sizeof(char), 1, fp); //2진 파일 쓰기
		if (count < 1) {
			fprintf(stderr, "Error while writing a character.\n");
			exit(1);
		}
	}

	rewind(fp);//읽기 모드를 위해 위치 포인터를 파일 처음으로 되돌림
	while (  fread((void*)&ch, sizeof(char), 1, fp)  ) {//2진파일읽기 ch받아드림
		ch = (ch - key) % 128;//원래 문자 복원
		if (ch < 0)
			ch += 128;
		fputc(ch, stdout);
	}

	if (feof(fp) != 1) {//fp가 파일끝이 아니라면
		printf("Error.\n");
		exit(1);
	}

	fclose(fp);//파일 닫기
	return 0;
}