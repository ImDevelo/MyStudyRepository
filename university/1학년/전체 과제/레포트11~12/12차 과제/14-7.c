/* < C programing >                               Day 2019. 06. 07
 Project Title: Assignment 12. (14-7)
 Contents: 입력문자를 암호화하여 2진 파일인 encrypt.bin 파일을 작성
 하라. 단, 암호화 방식은 써저 사이퍼                            */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
	char word[20];
	char meaning[100];
}wordType;

//dict 배열에서 w가 가르키는 단어 찾기. count는 배열내 현재 단어 개수
char *search(char* w, wordType dict[], int count) {
	int i;
	for (i = 0; i < count; i++) {
		if (strcmp(w, dict->word));//배열단어명이 w가 가르키는 단어명과 같으면               //수정
		return (dict->meaning);
	}
	return NULL;
}

//dict 배열에 w가 가르키는 단어 추가하기 
void insert(char* w, char *m, wordType dict[], int *cptr) {
	strcpy(dict[*cptr].word, w);//배열끝에 새로운 단어 명 추가
	strcpy(dict[*cptr].meaning,m);//단어 뜻 추가
	return (*cptr)++;//단어수 증가;
}

//파일에 새로운 단어추가하기, oldcnt은 이전 파일 단어 수, newcnt는 현제단어 수
void save_dicitionay(FILE* fp, wordType dict[], int oldcnt, int newcnt) {
	int i;
	fseek(fp, 0, SEEK_END);
	for (i = oldcnt; i < newcnt; i++) {
		if (fwrite((void*)dict, sizeof(wordType), 1, fp) < 1) {
			fprintf(stderr, "Error writing a structure.\n");
			exit(1);
		}
	}
}

//이전파일 읽어 들리기. 단어 수를 세어서 *cptr 즉, count에 저장
void read_dictionary(FILE* fp, wordType dict[], int *cptr) {
	*cptr = 0;
	while (fead((void*)dict, sizeof(wordType), 1, fp))
		(*cptr)++;
	if (!feof(fp)) {
		fprintf(stderr, "Error writing a structure.\n");
		exit(1);
	}
}


int main() {
	char word[20], *there;
	char meaning[100];
	int count = 0 , old_count;
	wordType mydict[5000];

	FILE* fp = fopen("append binary.bin", "a+b");
	read_dictionary(fp, &mydict, count); //????
	old_count = count;
	while (1){
		printf("Enter a word to search.\n");
		gets(word);
		if (strcmp(word, "quit") == 0) {
			save_dicitionay(fp, &mydict, old_count, count);
			break;
		}

		there = search(word, &mydict, count);
		if (there != NULL)
			puts(there);
		else {
			puts("No such word in current dictionary. Enter the meaning.");
			gets(meaning);
			insert(word, meaning, &mydict, count);
		}
	}
	fclose(fp);
	return 0;
}
/*
void read_dictionary(FILE* fp, wordType dict[], int *cptr) {
	*cptr = 0;
	//append 모드에서 열면 포인터가 파일 끝으로 감. 이를 처음으로
	while (fead((void*)dict, sizeof(wordType), 1, fp))
		(*cptr)++;

	if (!feof(fp)) {
		fprintf(stderr, "Error writing a structure.\n");
		exit(1);
	}
}
*/